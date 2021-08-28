#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#define gc getchar
#define pc putchar
#else
#define gc getchar_unlocked
#define pc putchar_unlocked
#endif

using namespace std;

#define vi vector<int>
#define si set<int>
#define vs vector<string>
#define pii pair<int,int>
#define vpi vector<pii>
#define pri priority_queue<int>
#define rev_pri priority_queue<int,vector<int>,greater<int> >
#define mpi map<int,int>
#define i64 long long int
#define endl '\n'
#define pi acos(-1)
#define all(v) v.begin(),v.end()
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define inf INT_MAX/2
#define infll LLONG_MAX/3
#define For(i,n) for(int i=0;i<n;i++)
#define Fre(i,a,b) for(int i = a; i < b; i++)
#define sf(n) scanf("%d", &n)
#define sff(a,b) scanf("%d %d", &a, &b)
#define sfff(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define pfn(n) printf("%d\n", n)
#define pfs(n) printf("%d ", n)
#define eps 1e-8
#define ff first
#define ss second
#define mem(a,b) memset(a,b,sizeof(a))
#define READ freopen("in.txt", "r", stdin)
#define WRITE freopen("out.txt", "w", stdout)
#define sz size()
#define dbg(i) printf("yo %d\n", i)
#define foreach(i,c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define sqr(a) (a) * (a)
#define clr clear()
#define CASE(a) printf("Case %d: ",a)

//int dx[] = {0,1,0,-1,1,1,-1,-1};
//int dy[] = {1,0,-1,0,1,-1,-1,1};


//i64 gcd(i64 a,i64 b){if(!b)return a;return gcd(b,a%b);}

//inline void fastRead(int *a){register char c=0;while(c<33)c=gc();*a=0;while(c>33){*a=*a*10+c-'0';c=gc();}}

//inline void fastWrite(int a){char snum[20];int i=0;do{snum[i++]=a%10+48;a=a/10;}while(a!=0);i=i-1;while(i>=0)pc(snum[i--]);pc('\n');}

//i64 bigmod(i64 num,i64 n){if(n==0)return 1;i64 x=bigmod(num,n/2);x=x*x%mod;if(n%2==1)x=x*num%mod;return x;}

//i64 modinverse(i64 num){return bigmod(num,mod-2)%mod;}

//i64 po(i64 a,i64 b){i64 ans=1;while(b--)ans *= a;return ans;}

//i64 ncr(i64 n,i64 r){if(n==r)return 1;if(r==1)return n;if(dp[n][r]!=-1)return dp[n][r];return dp[n][r]=ncr(n-1,r)+ncr(n-1,r-1);}


// bit manipulations

//bool checkbit(int mask,int bit){return mask & (1<<bit);}

//int setbit(int mask,int bit){ return mask  (1<<bit) ; }

//int clearbit(int mask,int bit){return mask & ~(1<<bit);}

//int togglebit(int mask,int bit){return mask ^ (1<<bit);}




/*
https://medium.com/carpanese/a-visual-introduction-to-treap-data-structure-part-1-6196d6cc12ee
Main concept:
Every node has a pair ( x, y)
the tree is binary search tree by x, and a binary heap by y
x is the key, y is the priority
if we randomize y, the height becomes approx logn

why though?
lets say we insert 1 to n serially in a bst. The height will be n
But if we just do a random shuffle of 1-10 and insert. the height will be log(n) approx
That’s an interesting fact, but it’s also almost useless because we have to read all insertions first.
The treap, however, is a data structure that can help us shuffle the keys in a smart way after each insertion.
The idea is that we can insert all the keys in the worst possible way (which means in a sorted way),
but the random priority will make sure to shuffle it “in real time”.
*/

/*
https://www.youtube.com/watch?v=6x0UlIBLRsc
https://www.spoj.com/problems/HORRIBLE/
*/

struct TreapNode {
        int priority,subtreeSize;
        i64 data;
        TreapNode *left,*right;

        // problem specific
        i64 sum, lazy;


        TreapNode(i64 data) {
                this->data = data;
                this->priority = rand();
                this->left = NULL;
                this->right = NULL;
                this->subtreeSize = 1;

                // problem specific
                this->sum = data;
                this->lazy = 0;
        }
};


void recalculate(TreapNode* node) {
        node->subtreeSize = 1;
        node->sum = node->data + node->lazy * node->subtreeSize;

        if(node->left != NULL) {
                node->subtreeSize += node->left->subtreeSize;
                node->sum += node->left->sum + node->left->lazy * node->left->subtreeSize;
        }

        if(node->right != NULL) {
                node->subtreeSize += node->right->subtreeSize;
                node->sum += node->right->sum + node->right->lazy * node->right->subtreeSize;
        }
}

void propagate(TreapNode* node) {
        if(node == NULL) return;

        if(node->left != NULL) node->left->lazy += node->lazy;
        if(node->right != NULL) node->right->lazy += node->lazy;

        node->data += node->lazy;
        node->lazy = 0;

        recalculate(node);

}

int getSize(TreapNode* node) {
        if(node == NULL) return 0;
        return node->subtreeSize;
}


pair<TreapNode*,TreapNode*> split(TreapNode* node,int leftSubtreeTargetSize) {
        if(node == NULL) return {NULL,NULL};
        propagate(node);
        if( getSize(node->left) >= leftSubtreeTargetSize) {
                // split the left node
                auto splitLeftNode = split(node->left, leftSubtreeTargetSize);
                node->left = splitLeftNode.second;
                recalculate(node);
                return {splitLeftNode.first, node};
        } else {
                // split the right node
                leftSubtreeTargetSize = leftSubtreeTargetSize - getSize(node->left) - 1;
                auto splitRightNode = split(node->right, leftSubtreeTargetSize);
                node->right = splitRightNode.first;
                recalculate(node);
                return {node, splitRightNode.second};
        }
}

TreapNode* merge(TreapNode* l, TreapNode* r) {
        if(l == NULL) return r;
        if(r == NULL) return l;
        propagate(l);
        propagate(r);
        if(l->priority < r->priority) {
                l->right = merge(l->right,r);
                recalculate(l);
                return l;
        } else {
                r->left = merge(l,r->left);
                recalculate(r);
                return r;
        }
}

// l,r 0th index
TreapNode* rangeAdd(TreapNode* treap,int l,int r,int toAdd) {
        auto a = split(treap,l);
        auto b = split(a.ss,r-l+1);

        (b.ff)->lazy += toAdd;
        return merge(a.ff,merge(b.ff,b.ss));
}

// l,r 0th index
i64 rangeSum(TreapNode* treap,int l,int r) {
        auto a = split(treap,l);
        auto b = split(a.ss,r-l+1);

        auto ans = (b.ff)->sum;

        merge(a.ff,merge(b.ff,b.ss));

        return ans;
}

int main() {

        srand(time(NULL));
        int t,n,q;
        sf(t);
        while(t--) {
                TreapNode* treap = NULL;
                sff(n,q);

                For(i,n)
                        treap = merge(treap,new TreapNode(0));

                while(q--) {
                        int l,r,toAdd,op;
                        sfff(op,l,r);
                        l--;
                        r--;
                        if(!op) {
                                sf(toAdd);
                                rangeAdd(treap,l,r,toAdd);
                        } else {
                                printf("%lld\n",rangeSum(treap,l,r));
                        }
                }
        }











        return 0;
}

