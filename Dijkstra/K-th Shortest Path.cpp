
#define k 2

vpi adj[5005];
vi dist[5005];

void dijk()
{
    priority_queue<pii, vpi, greater<pii> > pq;

    pq.push(mp(0,1));

    while(!pq.empty())
    {
        pii u = pq.top();
        pq.pop();

        if(!dist[u.ss].sz)
            dist[u.ss].pb(u.ff);
        else if(dist[u.ss].back() != u.ff)
            dist[u.ss].pb(u.ff);

        if(dist[u.ss].sz > k)
            continue;

        For(i,adj[u.ss].sz)
        {
            pii v = adj[u.ss][i];
            if(dist[v.ff].sz == k)
                continue;
            int curr = v.ss + u.ff;
            pq.push(mp(curr,v.ff));
        }
    }
}

int main()
{
    int t;
    cin >> t;
    Rep(tc,1,t)
    {
        int n,r;
        cin >> n >> r;
        mem(adj,NULL);
        mem(dist,NULL);
        while(r--)
        {
            int a,b,c;
            cin >> a >> b >> c;
            adj[a].pb(mp(b,c));
            adj[b].pb(mp(a,c));
        }

        dijk();
        CASE(tc);
        cout << dist[n][1] << endl;
    }

    return 0;
}
