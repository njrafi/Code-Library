#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define vs vector<string>
#define pii pair<int,int>
#define vpi vector<pii>
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
#define sz size()
#define dbg(i) printf("yo %d\n", i)
#define foreach(i,c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define sqr(a) (a) * (a)
#define clr clear()
#define CASE(a) printf("Case %d: ",a)

//int dx[] = {0,1,0,-1,1,1,-1,-1};
//int dy[] = {1,0,-1,0,1,-1,-1,1};

// bit manipulations

//bool checkbit(int mask,int bit){return mask & (1<<bit);}

//int setbit(int mask,int bit){ return mask | (1<<bit) ; }

//int clearbit(int mask,int bit){return mask & ~(1<<bit);}

//int togglebit(int mask,int bit){return mask ^ (1<<bit);}


int cnt[1002];

int main()

{
        int n,inp;
        sf(n);
        vi v;

        while(n--)
        {
                sf(inp);
                if(inp > 0)
                        cnt[inp]++;
                else if(!inp)
                        v.pb(0);
                else
                {
                        inp = abs(-inp);
                        if( cnt[inp])
                                cnt[inp]--;
                        else
                                v.pb(inp);
                }
        }


        bool ok = 1;
        vi ans;
        int zero = 0;
        For(i,v.sz)
                if(!v[i])
                        zero++;
                else
                {
                        if(zero)
                        {
                                zero--;
                                ans.pb(v[i]);
                        }
                        else
                        {
                                ok = 0;
                                break;
                        }
                }

        if(!ok)
                puts("No");
        else
        {
                puts("Yes");
                For(i,ans.sz)
                        cout << ans[i] << " ";
                For(i,zero)
                        cout << 1 << " ";
                cout << endl;
        }




}
