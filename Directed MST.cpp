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




/// Implemented from Pinada
/// Complexity is less than O ( n * m ) :p

struct edge
{
	int u, v, w;
	edge() {}
	edge(int a,int b,int c) : u(a), v(b), w(c) {}
	bool operator < (const edge& o) const
	{
		if (u == o.u)
			if (v == o.v)
				return w < o.w;
			else
				return v < o.v;
		return u < o.u;
	}
};

int dmst(vector<edge> &edges, int root, int n)
{
	int ans = 0;
	int cur_nodes = n;
	while (true)
	{
		vector<int> lo(cur_nodes, inf), pi(cur_nodes, inf);
		for (int i = 0; i < edges.size(); ++i)
		{
			int u = edges[i].u, v = edges[i].v, w = edges[i].w;
			if (w < lo[v] and u != v)
			{
				lo[v] = w;
				pi[v] = u;
			}
		}

		lo[root] = 0;
		for (int i = 0; i < lo.size(); ++i)
		{
			if (i == root)
				continue;
			if (lo[i] == inf)
				return -1;
		}
		int cur_id = 0;
		vector<int> id(cur_nodes, -1), mark(cur_nodes, -1);
		for (int i = 0; i < cur_nodes; ++i)
		{
			ans += lo[i];
			int u = i;
			while (u != root and id[u] < 0 and mark[u] != i)
			{
				mark[u] = i;
				u = pi[u];
			}
			if (u != root and id[u] < 0)   // Cycle
			{
				for (int v = pi[u]; v != u; v = pi[v])
					id[v] = cur_id;
				id[u] = cur_id++;
			}
		}

		if (cur_id == 0)
			break;

		for (int i = 0; i < cur_nodes; ++i)
			if (id[i] < 0)
				id[i] = cur_id++;

		for (int i = 0; i < edges.size(); ++i)
		{
			int u = edges[i].u, v = edges[i].v, w = edges[i].w;
			edges[i].u = id[u];
			edges[i].v = id[v];
			if (id[u] != id[v])
				edges[i].w -= lo[v];
		}
		cur_nodes = cur_id;
		root = id[root];
	}

	return ans;
}


int main()
{
        int t,cs = 1,n,m,k;
	sf(t);
	while(t--)
        {
                sfff(n,m,k);
                vector<edge> edges(m);
                For(i,m)
                        sfff(edges[i].u,edges[i].v,edges[i].w);

                int ans  =  dmst(edges, k, n);

                CASE(cs++);
                if (ans < 0)
                        printf("impossible\n");
                else
                        printf("%d\n", ans);
        }


	return 0;
}
