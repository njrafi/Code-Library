
/// Dinic's algorithm for directed graphs (0 based index for graphs)
/// Complexity( E * V^2)
/// For undirected graphs, just add two directed edges
/// implemented from zahin vai library
/// For normal edge just use the flow 
/// initilize with just source and sink
/// For nodeFlow initialize it source , sink  and node capacity graph



#define mxn 30004       // vertex number


namespace flow
{
        struct edge
        {
                int u,v;
                long long cap,flow;

                edge(){}
                edge(int a,int b,long long c,long long f)
                {
                        u = a , v = b , cap = c , flow = f;
                }
        };

        vi adj[mxn];
        vector<edge> e;

        int s,t,ptr[mxn], dis[mxn];

        /// initialize things
        void init(int source,int sink)
        {

                e.clr;
                mem(adj,NULL);

                s = source;
                t = sink;
        }


        /// adds a directed edge from a to b with capacity c

        void addEdge(int a,int b,long long c)
        {
                adj[a].pb(e.sz);
                e.pb(edge(a,b,c,0));


                adj[b].pb(e.sz);
                e.pb(edge(b,a,0,0));

        }

        /// just a bfs from source to sink
        /// return 1 if sink is reachable

        bool bfs()
        {
                mem(dis,-1);
                dis[s] = 0;
                queue<int> q;
                q.push(s);

                while(!q.empty() && dis[t] == -1)
                {
                        int u = q.front();
                        q.pop();
                        For(i,adj[u].sz)
                        {
                                int id = adj[u][i];
                                int v = e[id].v;

                                if(dis[v]==-1 && e[id].flow < e[id].cap)
                                {
                                        q.push(v);
                                        dis[v] = dis[u] + 1;
                                }
                        }
                }

                return (dis[t]!=-1);

        }



        long long dfs(int u,long long f)
        {
                if(u == t || !f)
                        return f;


                while(ptr[u] < adj[u].sz)
                {
                        int id = adj[u][ptr[u]];
                        int v = e[id].v;

                        if(dis[v] == dis[u] + 1)
                        {
                               long long x = dfs(v,min(f,e[id].cap - e[id].flow));

                               if(x)
                               {
                                       e[id].flow += x;
                                       e[id ^ 1].flow -= x;
                                       return x;
                               }
                        }
                        ptr[u]++;
                }

                return 0;
        }

        long long dinic()
        {
                long long res = 0;

                while(bfs())
                {
                        mem(ptr,0);
                        while(long long f = dfs(s,infll))
                                res += f;
                }
                return res;
        }
}

namespace nodeFlow
{
        void init(int n,int s,int t, vector<i64> capacity)
        {
                flow::init(s*2,t*2+1);

                for(int i = 0 ; i < n ; i ++)
                        flow::addEdge(i * 2 ,i * 2 + 1 , capacity[i] );
                /// converting the node to edge

        }

        void addEdge(int a,int b,long long c)
        {
                flow::addEdge(a*2+1,b*2,c);
        }


        long long dinic()
        {
                return flow::dinic();
        }
}

int main()
{
        int tt,n,inp,a,b,c , cs = 1;
        sf(tt);
        while(tt--)
        {
                vector<long long> v;
                sf(n);
                For(i,n)
                {
                        sf(inp);
                        v.pb(inp);
                }

                v.pb(infll);
                v.pb(infll);


                n += 2;

                int sou = n - 2;
                int sink = n - 1;

                nodeFlow::init(n,sou,sink,v);

                sf(inp);

                while(inp--)
                {
                        sfff(a,b,c);
                        nodeFlow::addEdge(a-1,b-1,c);
                }

                sff(a,b);

                while(a--)
                {
                        sf(inp);
                        nodeFlow::addEdge(sou,inp-1,infll);
                }

                while(b--)
                {
                        sf(inp);
                        nodeFlow::addEdge(inp-1,sink,infll);
                }


                CASE(cs++);
                cout << nodeFlow::dinic() << endl;
        }
        return 0;
}

