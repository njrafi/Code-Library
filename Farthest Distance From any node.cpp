

/// Gives us the farthest node from any node i

#define mxn 50005
vpi v[mxn];

// dp contains the max value for every children
// in dfs2 parent info is also added
// (max distance, which node)
vpi dp[mxn];                            
                                        
int vis[mxn];


// Calculating for subtree of every node
int dfs(int s)                          
{
        vis[s] = 1;
        int ans = 0;
        For(i,v[s].sz)
        {
                int vv = v[s][i].ff;
                int ww = v[s][i].ss;
                if(!vis[vv])
                {

                        int tem = dfs(vv) + ww;
                        ans = max(tem,ans);
                        dp[s].pb(mp(-tem,vv));
                }
        }

        // sorting for getting the max distance children first
        sort(all(dp[s]));                   
        return ans;

}


void dfs2(int s,int par,int paredge)
{

        vis[s] = 1;
        if(par!=-1)
        {
                int mx = 0;
                For(i,dp[par].sz)
                        if(dp[par][i].ss!=s)                    
                        {
                                /// If a max value is for this node choose the next one
                                mx = -dp[par][i].ff;
                                break;
                        }
                ///  distance for parent
                int pval = mx + paredge;                        
                dp[s].pb(mp(-pval,par));
                sort(all(dp[s]));
        }
        For(i,v[s].sz)
        {
                int vv = v[s][i].ff;
                int ww = v[s][i].ss;
                if(!vis[vv])
                        dfs2(vv,s,ww);
        }
}


int main()
{

        int n,a,b,c;
        sf(n);
        For(i,n-1)
        {
            sfff(a,b,c);
            v[a].pb(mp(b,c));
            v[b].pb(mp(a,c));
        }

        dfs(1);

        mem(vis,0);
        dfs2(1,-1,-1);

        Fre(i,1,n+1)
                cout << -dp[i][0].ff << endl;
        return 0;
}
