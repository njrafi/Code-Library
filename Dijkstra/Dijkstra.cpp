

vpi edge[100005];
i64 dis[100005];
int pre[100005],n;

void ini()
{

        fill(dis,dis+100005,infll);
        mem(pre,-1);
}

void func(int source)
{
        ini();
        dis[source] = 0;
        priority_queue<pii,vector<pii>,greater<pii> > p;
        p.push(mp(0,source));
        while(!p.empty())
        {
                int u = p.top().ss;
                p.pop();
                if(u==n)
                        break;
                For(i,edge[u].sz)
                {
                        int v = edge[u][i].ff;
                        i64 d = edge[u][i].ss;
                        if(dis[u]+d<dis[v])
                        {
                                dis[v] = d+dis[u];
                                pre[v] = u;
                                p.push(mp(dis[v],v));
                        }
                }
        }


        // printing path
        if(pre[n]==-1)
        {
                cout << -1;
                return;
        }
        vi ans;
        ans.pb(n);
        while(n!=1)
        {
                n = pre[n];
                ans.pb(n);
        }
        reverse(all(ans));
        For(i,ans.sz)
                cout << ans[i] << " ";
}

int main()
{

        ios_base::sync_with_stdio(false);cin.tie(0);
        int m,a,b,c;
        cin >> n >> m;
        while(m--)
        {
                cin >> a >> b >> c;
                edge[a].pb(mp(b,c));
                edge[b].pb(mp(a,c));
        }
        func(1);

        return 0;
}
