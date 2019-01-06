
#define maxn 10005

/// Holding the articulation points
set<int> point;
bool vis[maxn];
int low[maxn],d[maxn],timen,parent[maxn],root;
vi v[maxn];



void dfs(int s)
{
        timen++;
        vis[s] = 1;
        low[s] =  d[s] = timen;
        int child = 0;

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

                        if(d[s]<=low[w] && s!=root)
                                point.insert(s);

                        child++;
                }
        }

        if(child>1 && s==root)
                point.insert(s);


}



void ini()
{
        point.clr;
        mem(vis,0);
        timen = 0;
        mem(parent,-1);
        mem(v,NULL);
}


int main()
{


        int t,n,m,a,b,c=1;

        sf(t);

        while(t--)
        {

                ini();
                sff(n,m);
                while(m--)
                {
                        sff(a,b);
                        v[a].pb(b);
                        v[b].pb(a);
                }
                Fre(i,1,n+1)
                        if(!vis[i])
                        {
                                root = i;
                                dfs(root);
                        }

                CASE(c++);
                pfn(point.sz);
        }

        return 0;
}

