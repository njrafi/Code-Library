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
Hashing mechanism

hash = val[node] or p2(if all nodes are considered same)



for every children:
        hash = hash * p ^ ( child subtree size) + ( val[node] or p2(if all nodes are considered same))
        thisNodeSize += child subtree size
        hash = hash * p + (some value of garbage node)
        thisNodeSize++

if all the nodes are same we sort the children first before calculating hash

return {hash , thisNodeSize}


*/

/// remember to calculate highest prime powers properly


#define ui64 unsigned long long
#define p1 163
#define p2 33
#define mxn 10004


char gg[mxn];
string s[2];
vi v[2][mxn];
int par[mxn];

void make_tree(int idx)
{

        mem(v[idx],NULL);
        int now = 1;
        int freeNode = 2;

        For(i,s[idx].sz)
        {
                if(s[idx][i]=='1')
                {
                        v[idx][now].pb(freeNode);

                        par[freeNode] = now;
                        now = freeNode;

                        freeNode++;
                }
                else
                        now = par[now];
        }

}

ui64 p[mxn*3];




void pre()
{
        p[0] = 1;

        Fre(i,1,mxn*3)
                p[i] = p[i-1] * (ui64)p1;
}

/// gives hash , subtree size of a node
/// the subtree size is not the actual subtree size
/// because we are adding garbage node
pair<ui64,int> f(int idx,int u = 1)
{

        /// node e value thakle change p2 to that value

        ui64 ans = p2;
        int nowsz = 1;

        vector< pair<ui64,int> > ggla;


        For(i,v[idx][u].sz)
        {

                int vv = v[idx][u][i];
                pair<ui64,int> gg = f(idx,vv);
                ggla.pb(gg);


        }

        sort(all(ggla));

        For(i,ggla.sz)
        {

                pair<ui64,int> gg = ggla[i];
                nowsz += gg.ss;
                ans = ans * (ui64)p[gg.ss] + gg.ff;


                /// adding a garbage node between children
                ans = ans * p1 + 500;
                nowsz ++;


        }
        return mp(ans,nowsz);
}

int main()
{
        pre();
        int t,cs = 1;
        sf(t);
        getchar();
        while(t--)
        {
                gets(gg);
                s[0] = gg;
                gets(gg);
                s[1] = gg;

                make_tree(0);
                make_tree(1);

//                cout << f(0,1).ff << endl;
//                cout << f(1,1).ff << endl;

                CASE(cs++);
                if(f(0,1).ff != f(1,1).ff)
                        puts("Different");
                else
                        puts("Same");
        }




        return 0;
}


