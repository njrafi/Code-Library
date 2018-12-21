
#define mxn 300005

i64 dis[mxn];


struct edge
{
        int v,cost,idx;
};

vector<edge> v[mxn];

/// Calling The Dijkstra
void dij()
{
        For(i,mxn)
                dis[i] = infll;
        priority_queue< pair<i64,int> , vector< pair<i64,int> > , greater< pair<i64,int> > > p;


        dis[1] = 0;
        p.push({0,1});


        while( !p.empty())
        {
                int u = p.top().ss;
                i64 udis = p.top().ff;

                p.pop();

                if(dis[u] < udis)
                        continue;

                For(i,v[u].sz)
                {
                        int vv = v[u][i].v;
                        i64 cost = v[u][i].cost;


                        if(dis[vv] > udis + cost)
                        {
                                dis[vv] = udis + cost;
                                p.push({dis[vv],vv});
                        }
                }

        }



}


vpi ans;
bool vis[mxn];


/// Making the Dijkstra tree
void dfs(int u,i64 d,int lvl)
{
        vis[u] = 1;

        For(i,v[u].sz)
        {
                int vv = v[u][i].v;
                i64 cost = v[u][i].cost;
                int idx = v[u][i].idx;

                if(!vis[vv] && d + cost == dis[vv])
                {
                        ans.pb({lvl,idx});
                        dfs(vv,d+cost,lvl+1);
                }

        }
}

int main()
{

        int n,m,k,a,b,c;
        sfff(n,m,k);

        Fre(i,1,m+1)
        {
                sfff(a,b,c);

                v[a].pb({b,c,i});
                v[b].pb({a,c,i});
        }

        dij();


        dfs(1,0,1);
        sort(all(ans));

        while(ans.sz > k)
                ans.pop_back();

        pfn(ans.sz);

        For(i,ans.sz)
                pfs(ans[i].ss);





        return 0;
}


