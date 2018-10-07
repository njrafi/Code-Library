#define mxn 100005


vi v[mxn];
bool vis[mxn];
int rs[mxn] , fc[mxn];
i64 dp[mxn][6];

/// converting  to binary tree
void dfs(int n)                 
{

        vis[n] = 1;

        vi c;
        For(i,v[n].sz)
                if(!vis[v[n][i]])
                        c.pb(v[n][i]);

        if(!c.empty())
                fc[n] = c[0];

        For(i,(int)c.sz-1)
                rs[c[i]] = c[i+1];

        For(i,c.sz)
                dfs(c[i]);
}

i64 f(int n,int par)
{
        if(!n)
        {
                if(par==1 || par==3)
                        return 1;
                return 0;
        }
        if(dp[n][par]!=-1)
                return dp[n][par];

        i64 ans ;

        if(!par)
        {
                ans = (f(fc[n],1) * f(rs[n],1)) % mod;
                ans += ( f(fc[n],2) * f(rs[n],0) ) % mod;
        }
        else if(par==1)
        {
                ans = ( f(fc[n],1) * f(rs[n],1) ) % mod;
                ans += ( f(fc[n],2) * f(rs[n],1) ) % mod;
        }
        else if(par==2)
        {
                ans = ( f(fc[n],0) * f(rs[n],2) ) % mod;
                ans += ( f(fc[n],3) * f(rs[n],3) ) % mod;
        }
        else
        {
                ans = ( f(fc[n],0) * f(rs[n],3)) % mod;
                ans += ( f(fc[n],3) * f(rs[n],3)) % mod;
        }

        return dp[n][par] = ans % mod;
}



int main()
{

        int n , a , b;
        sf(n);

        For(i,n-1)
        {
                sff(a,b);
                v[a].pb(b);
                v[b].pb(a);
        }



        vi st;

        Fre(i,1,n+1)
                if(!vis[i])
                {
                        st.pb(i);
                        dfs(i);
                }
        mem(dp,-1);

//
//        Fre(i,1,n+1)
//                cout << i << " " << fc[i] << " " << rs[i] << endl;

        i64 ans = 0;
        For(i,st.sz)
                ans = (ans + ( f(fc[st[i]],0) + f(fc[st[i]],2)) % mod ) % mod;

        cout << ans << endl;;




        return 0;
}

