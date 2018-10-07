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
USER: zobayer
TASK: BSHEEP
ALGO: convex hull
*/

/// Change to double if needed
struct point
{
	int x, y, id;
};

inline double dist(const point &a, const point &b)
{
	return hypot((double)(a.x-b.x), (double)(a.y-b.y));
}

namespace ConvexHull
{
        int np,nc;
        // np = total number of points
        // nc = convex hull points

const int maxPoint =  100005;




point P[maxPoint], C[maxPoint], P0;

/// Triangle area from 3 points
inline i64 triArea2(const point &a, const point &b, const point &c)
{
	return (a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y));
}

inline i64 sqDist(const point &a, const point &b)
{
	return ((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}



inline bool comp(const point &a, const point &b)
{
	int d = triArea2(P0, a, b);
	if(d < 0)
		return false;
	if(!d && sqDist(P0, a) > sqDist(P0, b))
		return false;
	return true;
}

inline bool normal(const point &a, const point &b)
{
	return ((a.x==b.x) ? a.y < b.y : a.x < b.x);
}

inline bool issame(const point &a, const point &b)
{
	return (a.x == b.x && a.y == b.y);
}

inline void makeUnique(int &np)
{
	sort(P, P+np, normal);
	np = unique(P, P+np, issame) - P;
}

void convexHull(int &np, int &nc)
{
	int i, j, pos = 0;
	for(i = 1; i < np; i++)
		if(P[i].y<P[pos].y || (P[i].y==P[pos].y && P[i].x<P[pos].x))
			pos = i;
	swap(P[0], P[pos]);
	P0 = P[0];
	sort(&P[1], &P[np], comp);
	for(i = 0; i < 3; i++)
		C[i] = P[i];
	for(i = j = 3; i < np; i++)
	{
		while(triArea2(C[j-2], C[j-1], P[i]) < 0)
			j--;
		C[j++] = P[i];
	}
	nc = j;
}

void compress(int &nc)
{
	int i, j, d;
	C[nc] = C[0];
	for(i=j=1; i < nc; i++)
	{
		d = triArea2(C[j-1], C[i], C[i+1]);
		if(d || (!d && C[j-1].id == C[i+1].id))
			C[j++] = C[i];
	}
	nc = j;
}


void input()
{
        scanf("%d", &np);
        For(i,np)
        {
                sff(P[i].x, P[i].y);
                P[i].id = i + 1;
        }
}


vector<point> get_hull()
{
        makeUnique(np);
        vector<point> v;


        /// handle properly
        if(np<3)
        {
                For(i,np)
                        v.pb(P[i]);
                return v;
        }

        convexHull(np, nc);
        compress(nc);

        For(i,nc)
                v.pb(C[i]);

        return v;
}



}
int main()
{
        int t;
	scanf("%d", &t);
	while(t--)
	{


		ConvexHull::input();
		vector<point> v = ConvexHull::get_hull();
		double perim = 0;

		if(v.sz==1)
		{
			printf("0.00\n");
			printf("%d\n", v[0].id);
		}
		else if(v.sz==2)
		{
			perim = 2.0 * dist(v[0], v[1]);
			printf("%.2f\n", perim + eps);
			printf("%d %d\n", v[0].id, v[1].id);
		}
		else
		{
                        perim = dist(v.back(),v[0]);
			For(i,v.sz-1)
				perim += dist(v[i], v[i+1]);
			printf("%.2f\n", perim + eps);
			printf("%d", v[0].id);
			Fre(i,1,v.sz)
				printf(" %d", v[i].id);
			printf("\n");
		}
		if(t)
			printf("\n");
	}
	return 0;
}


