
#define mxn 505

vector<info> node;

int matchL[mxn] , matchR[mxn];
bool vis[mxn];
int parent[mxn];
int dis[mxn];
vi v[mxn];

int findmatch(int u)
{
        vis[u] = 1;

        For(i,v[u].sz)
        {
                int vv = v[u][i];
                int k = matchR[vv];

                if(!matchR[vv] || parent[matchR[vv]] == u)
                {

                        if(!matchR[vv] || findmatch(k))
                        {

                                matchL[u] = vv;
                                matchR[vv] = u;
                                return 1;
                        }
                }


        }

        return 0;
}

bool bfs()
{
        mem(vis,0);
        queue<int> q;


        Fre(i,1,node.sz)
                if(!matchL[i])
                {
                        vis[i] = 1;
                        q.push(i);
                        dis[i] = 0;
                }

        while(!q.empty())
        {
                int u = q.front();
                q.pop();

                For(i,v[u].sz)
                {
                        int vv = v[u][i];
                        int d = matchR[vv];

                        if(!d)
                                return 1;
                        else if(!vis[d])
                        {
                                q.push(d);
                                parent[d] = u;
                                vis[d] = 1;
                                dis[d] = dis[u] + 1;
                        }
                }
        }
        return 0;

}


int bpm()
{
        int ans = 0;



        while(bfs())
        {
                Fre(i,1,node.sz)
                        if(!matchL[i] && findmatch(i))
                                ans++;

        }

        mem(matchL,0);
        mem(matchR,0);
        node.clr;
        mem(v,NULL);

        return ans;
}



