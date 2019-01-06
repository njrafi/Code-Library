
#define mxn 300005


vi v[mxn]; /// Main Graph

/// for finding bridge
int timen,parent[mxn],root,d[mxn],low[mxn];

bool vis[mxn];


/// Is Bridge?
map<pii,bool> isb;

/// getting the bridges
void dfs(int s)
{
        vis[s] = 1;

        timen++;
        low[s] = d[s] = timen;

        For(i,v[s].sz)
        {
                int w = v[s][i];

                if(parent[s]==w)
                        continue;

                if(vis[w])
                        low[s] = min(low[s],d[w]);
                else
                {
                        parent[w] = s;
                        dfs(w);
                        low[s] = min(low[s],low[w]);

                        if(d[s]<low[w] )
                        {
                                isb[mp(s,w)] = 1;
                                isb[mp(w,s)] = 1;
                        }
                }
        }
}


void ini()
{
        timen = 0;
        mem(parent,-1);
        mem(v,NULL);

}


vi w[mxn]; /// new tree
int fcomp; /// free component

/// This dfs will make a tree using only the bridges as its edge
/// if 2 nodes are connected without a bridge, they will be considered as same node

void dfs2(int n,int comp)
{
        vis[n] = 1;

        For(i,v[n].sz)
        {
                int vv = v[n][i];
                if(vis[vv])
                        continue;


                if(isb.find(mp(n,vv))==isb.end())
                        dfs2(vv,comp);
                else
                {

                        w[comp].pb(fcomp);
                        w[fcomp].pb(comp);
                        fcomp++;
                        dfs2(vv,fcomp-1);
                }
        }
}


int dis[mxn];


int main()
{
        int a,b,n,m,cs=1;

        ini();

        sff(n,m);

        while(m--)
        {
                sff(a,b);
                v[a].pb(b);
                v[b].pb(a);
        }

        Fre(i,1,n+1)
        {
                if(!vis[i])
                {
                        root = i;
                        dfs(root);
                }
        }

        mem(vis,0);
        fcomp = 2;
        dfs2(1,1);

        /// This bfs would give us the diameter
        cout << dis[bfs(bfs(1,fcomp),fcomp)]  << endl;

        return 0;
}

