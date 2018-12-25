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




/// https://toph.co/c/tough-winter-spar-2018/arena#!/p/value-assignment-problem-2


#define mxn 100005


/// custom node for problem
/// Modify it
struct node
{
        int cnt;
        int u, p ;
        node(){}
        node(int _cnt,int uu,int pp)
        {
                cnt = _cnt;
                u = uu;
                p = pp;

        }
};

/// Custom merge function
node merge(node a,node b)
{
        if(!a.cnt) return b;
        else if(!b.cnt) return a;


        a.cnt += b.cnt;

        return a;
}

node tree[4 * mxn];
node lazy[4 * mxn];
bool lazyAche[4 * mxn];


/// Lazy process
/// Remember to Modify
void process(int n,int st,int en,node val)
{
        tree[n] = val;

        tree[n].cnt = val.cnt * (en - st + 1);

        lazyAche[n] = 0;

        if(st != en)
        {

                int lc = 2 * n , rc = lc + 1;

                lazyAche[lc] = 1;
                lazy[lc] = val;

                lazy[rc] = val;
                lazyAche[rc] = 1;
        }
}


/// Segtree range update
/// Dont modify (unless necessary)
void update(int n,int st,int en,int l,int r,node val)
{

        if(lazyAche[n])
                process(n,st,en,lazy[n]);

        if(r < st || en < l) return;

        if(l<=st && en<=r)
        {
                process(n,st,en,val);
                return;
        }

        int mid = (st+en)/2 , lc = 2 * n , rc = lc  + 1;


        update(lc,st,mid,l,r,val);
        update(rc,mid+1,en,l,r,val);

        tree[n] = merge(tree[lc] , tree[rc]);
}


/// Segtree Range Query
/// Dont modify (unless necessary)
node query(int n,int st,int en,int l,int r)
{

        if(lazyAche[n])
                process(n,st,en,lazy[n]);

        if(r < st || en < l)
                return node(0,0,0);
        if(l <= st && en <= r)
                return tree[n];

        int mid = (st+en)/2 , lc = 2 * n , rc = lc  + 1;


        node q1 = query(lc,st,mid,l,r);
        node q2 = query(rc,mid+1,en,l,r);

        return merge(q1 ,q2);
}

/// segtree ends///

int n;          /// node number
int par[mxn];   /// parent of nodes
int szz[mxn];   /// size of subtree
vi v[mxn];      /// The graph
int depth[mxn]; /// depth from root
int nxt[mxn];   /// Next node of the chain


/// dfs to calculate the subtree size
void dfs(int n,int pp = 0)
{

	par[n] = pp;
	szz[n] = 1;

	For(i,v[n].sz)
	{
		int vv = v[n][i];
		if(vv==pp)
			continue;
		depth[vv] = depth[n] + 1;

		dfs(vv,n);

		szz[n] += szz[vv];


		/// next node of chain is the heaviest child
		if(nxt[n] == -1 || szz[vv] > szz[nxt[n]])
			nxt[n] = vv;
	}
}

int chain[mxn]; /// which chain a node belongs to
int num[mxn];   /// The changed node number
int csz[mxn];   /// chain i size
int top[mxn];   /// top node of the chain i
int cnt = 1;    /// the count of chains
int all;        /// For changing node numbers

/// constructing chain
void hld(int n,int pp = -1)
{
	chain[n] = cnt - 1;

	num[n] = all++;

	/// if chain size zero top of the chain (cnt-1) is node n
	if(!csz[cnt-1])
		top[cnt-1] = n;

	csz[cnt-1]++;

	/// go down this chain
	if( nxt[n] != -1)
		hld(nxt[n],n);

	For(i,v[n].sz)
	{
		int vv = v[n][i];
		if(vv == pp || vv == nxt[n])
			continue;

		cnt++;

		/// going the other child to build other chains
		hld(vv,n);
	}
}




node tot[mxn];    /// Total Result of chain i

/// Getting result from a to b


/// Query between point a and b
/// in this problem distance between a and b
int distance(int a,int b)
{
        int ans = 0;
        while( chain[a] != chain[b])
        {
                /// we want the node with more depth chain in variable a
                if(depth[top[chain[a]]] < depth[top[chain[b]]] )
                        swap(a,b);

                int start = top[chain[a]];

                /// if full chain is included
                if(num[a] == num[start] + csz[chain[a]] - 1)
                        ans +=  tot[chain[a]].cnt;
                else
                        ans +=  query(1,1,n,num[start],num[a]).cnt;

                a = par[start];
        }

        if(depth[a] > depth[b])
                swap(a,b);

        ans += query(1,1,n,num[a],num[b]).cnt;

        return ans;
}


/// Updating range [a,b] with (u,p)
/// Change accordingly to problem
void updateRange(int a,int b,int u,int p)
{
        while( chain[a] != chain[b])
        {
                /// we want the node with more depth chain in variable a
                if(depth[top[chain[a]]] < depth[top[chain[b]]] )
                         swap(a,b);

                int start = top[chain[a]];

                update(1,1,n,num[start],num[a],node(1,u,p));

                int st = num[top[chain[a]]];
                int en = st + csz[chain[a]] - 1;

                tot[chain[a]] = query(1,1,n,st,en);

                a = par[start];
        }

        if(depth[a] > depth[b])
                swap(a,b);

        update(1,1,n,num[a],num[b],node(1,u,p));


        int st = num[top[chain[a]]];
        int en = st + csz[chain[a]] - 1;
        tot[chain[a]] = query(1,1,n,st,en);

        return;
}



/// changing value of node n to val or increase val
/// handle in the seg tree functions


///// Modify a single node
//void modify(int nd,node val)
//{
//        update(1,1,n,num[nd],num[nd],val);
//
//        int st = num[top[chain[nd]]];
//        int en = st + csz[chain[nd]] - 1;
//
//        tot[chain[nd]] = query(1,1,n,st,en);
//}



void ini()
{
	mem(nxt,-1);
	mem(szz,0);
	mem(v,NULL);
	mem(csz,0);
	cnt = 2;
	all = 1;
}


int D[mxn];

int main()
{
        int m,a,b;
        ini();
        sff(n,m);


        For(i,n-1)
        {
                sff(a,b);
                v[a].pb(b);
                v[b].pb(a);
        }

        Fre(i,1,m+1)
                sf(D[i]);


        dfs(1);
        hld(1);


        Fre(i,1,n+1)
                updateRange(i,i,0,0);



//        Fre(i,1,n+1)
//                cout << i << " " << num[i] << endl;

        int q;
        sf(q);

//        while(q--)
//        {
//                sff(a,b);
//
//                cout << distance(a,b) << endl;
//        }

        int l,r,p,op;
        while(q--)
        {
                sf(op);
                if(op==1)
                {
                        sfff(l,r,p);



                        updateRange(l,r,l,p);
                }
                else
                {
                        sf(l);

                        int u = query(1,1,n,num[l],num[l]).u;
                        int p = query(1,1,n,num[l],num[l]).p;

                        if(!u && !p) {
                                pfn(0);
                                continue;
                        }

                        int dis = distance(u,l) - 1;
//
//                        cout << "tree start : "<<  u << endl;
//                        cout << "array start : " << p <<endl;
//                        cout << "distance  :" << dis << endl;
//                        cout << "ans : ";
                        pfn(D[p + dis]);
                }
        }


	return 0;
}


