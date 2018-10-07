#define mxn 1005

int dis[mxn];
struct edge
{
        int a,b,c;
};


bool vis[mxn];

/// The actual Graph
vi g[mxn];

/// After the algo 
/// Visited nodes will be part of negative cycle
void dfs(int u)
{
        vis[u] = 1;
        For(i,g[u].sz)
        {
                int vv = g[u][i];
                if(!vis[vv]) dfs(vv);
        }
}

int main()
{

     
        int t,n,m,cs = 1;

        sf(t);
        while(t--)
        {
                edge tem;
                vector<edge> v;
                fill(dis,dis+mxn,inf);
                dis[0] = 0;
                mem(g,NULL);
                mem(vis,0);

                sff(n,m);


                while(m--)
                {
                        sfff(tem.a,tem.b,tem.c);
                        v.pb(tem);
                        g[tem.a].pb(tem.b);
                }


                For(k,n)
                {
                        For(i,v.sz)
                                if(dis[v[i].a]!=inf && dis[v[i].b]>dis[v[i].a]+v[i].c)
                                        dis[v[i].b] = dis[v[i].a] + v[i].c;
                }

                mem(vis,0);

                For(k,n)
                {
                        For(i,v.sz)
                                if(dis[v[i].a]!=inf && dis[v[i].b]>dis[v[i].a]+v[i].c)
                                        if(!vis[v[i].a])
                                                dfs(v[i].a);
                }

                CASE(cs++);
                if(!vis[0])
                        cout << "not ";
                cout << "possible" << endl;



        }
        return 0;
}
