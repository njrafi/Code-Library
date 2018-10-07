
map<string , int > mps;
int v[60][60];
int sou = 57 , sink = 58;
int par[205];
int mxf;

vi getpath()
{
        vi path;
        path.pb(sink);
        int now = sink ;
        while(now!=sou)
        {
                now = par[now];
                path.pb(now);
        }
        reverse(all(path));

        return path;
}


bool bfs()
{
        bool vis[60] = {0};
        vis[sou] = 1;
        queue<int> q;
        q.push(sou);
        while(!q.empty())
        {
                int u = q.front();
                q.pop();
                Fre(i,1,60)
                        if(v[u][i]>0 && !vis[i])
                        {
                                vis[i] = 1;
                                par[i] = u;
                                q.push(i);

                        }
        }

        if(!vis[sink])
                return 0;
        vi path = getpath();
        int mn = 1234567;

        For(i,path.sz-1)
                mn = min(mn,v[path[i]][path[i+1]]);
        For(i,path.sz-1)
        {
                v[path[i]][path[i+1]] -= mn;
                v[path[i+1]][path[i]] += mn;
        }

        mxf = mn;
        return 1;


}

int f()
{
        int ans = 0;
        while(bfs())
                ans += mxf;

        return ans;
}

