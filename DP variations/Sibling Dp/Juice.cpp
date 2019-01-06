
#define mxn 1002

pii info[mxn];
vi v[mxn];
/// Right Sibling
int rs[mxn] ;
/// First Childred
int fc[mxn];

int par[mxn];
int dp[mxn][102];

/// Converting to binary tree
void dfs(int n)
{

        if(v[n].sz)
                fc[n] = v[n][0];

        For(i,(int)v[n].sz-1)
                rs[v[n][i]] = v[n][i+1];

        For(i,v[n].sz)
                dfs(v[n][i]);
}



int f(int n,int volt)
{
        if(n==-1)
                return 0;
        if(dp[n][volt]!=-1)
                return dp[n][volt];

        int ans1 = 0 , ans2 = 0 , ans = 0;
        For(i,min(info[n].ss,volt) + 1)
        {
                int own = i;
                if(own>=info[n].ff)             // jalaia
                        ans1 = max( f(fc[n],own - info[n].ff) + 1 , f(fc[n],own));
                else
                        ans1 =  f(fc[n],own) ;


                int forsib = volt - i;
                if(!par[n])
                        forsib = 100;

                ans2 = f(rs[n], forsib);
                ans = max(ans, ans1 + ans2);
        }


        return dp[n][volt] = ans;

}

int main()
{

        int n , a , b , c;

        sf(n);
        Fre(i,1,n+1)
        {
                sfff(a,b,c);
                v[a].pb(i);
                info[i] = mp(b,c);
                par[i] = a;
        }


        mem(fc,-1);
        mem(rs,-1);
        mem(dp,-1);


        dfs(0);


        cout << f(fc[0],100) << endl;







        return 0;
}

