/*
euler path for undirected graph:
1. duita node baad e baki sob node er degree even
2. duita node er degree odd
3. graph ta connected.

euler cycle for undirected graph:
1. sob node er degree even
2. graph ta connected.

euler path for directed graph:
1. duita node baad e baki sob node er indegree == outdegree
2. ekta node er indegree = outdegree - 1 , arekta node er outdegree = indegree - 1
3. graph take undirected dhorle oi undirected graph ta connected.



euler cycle for directed graph:
1. sob node er indegree == outdegree
2. graph er sob node ekta strongly connected component


*/


vi v[30],vt[30],und[30] ,top ;
bool vis[30] , taken[30];
int nodes ;
int ind[30] , out[30] ;


void topo(int s)
{
        if(!taken[s])
        {
                taken[s] = 1;
                For(i,v[s].sz)
                        if(!taken[v[s][i]])
                                topo(v[s][i]);
                top.pb(s);
        }
}

void dfs2(int s)
{
        vis[s] = 1;
        For(i,vt[s].sz)
                if(!vis[vt[s][i]])
                        dfs2(vt[s][i]);
}

bool iscircuit()
{
        top.clr;
        mem(taken,0);
        For(i,26)
                if(!taken[i] && (ind[i] || out[i]) )
                        topo(i);
        int scc = 0;

        reverse(all(top));
        mem(vis,0);


        For(i,top.sz)
        {

                int u = top[i];
                if(!vis[u])
                {
                        scc++;
                        if(scc>1)
                                break;
                        dfs2(u);

                }
        }
        if(scc==1)
                return 1;
        return 0;
}

void dfs1(int s)
{
        vis[s] = 1;
        For(i,und[s].sz)
                if(!vis[und[s][i]])
                        dfs1(und[s][i]);
}

bool ispath()
{
        mem(vis,0);
        For(i,26)
                if(ind[i] || out[i])
                 {
                        dfs1(i);
                        break;
                }
        int cnt = 0;
        For(i,26)
                if(vis[i])
                        cnt++;
        if(cnt==nodes)
                return 1;
        return 0;

}
int main()
{

        int t,n;
        string s;
        sf(t);
        while(t--)
        {
                mem(ind,0);
                mem(out,0);
                mem(v,NULL);
                mem(vt,NULL);
                mem(und,NULL);

                sf(n);
                while(n--)
                {
                        cin >> s;

                        int u = s[0] - 'a';
                        int w = s[s.sz-1] - 'a';
                        v[u].pb(w);
                        und[u].pb(w);
                        vt[w].pb(u);
                        und[w].pb(u);

                        ind[w]++;
                        out[u]++;

                }

                int sou = 0 , des = 0 , soman = 0 ;
                nodes = 0;

                For(i,26)
                {

                        if(ind[i]==out[i] && ind[i])
                                soman++;
                        else if(ind[i]==out[i]-1)
                                des++;
                        else if(ind[i]-1==out[i])
                                sou++;

                        if(ind[i] || out[i])
                                nodes++;
                }

                bool ok = 0;
                if(soman==nodes)
                        ok = iscircuit();
                else if(sou==1 && des==1 && soman==nodes-2)
                        ok = ispath();

                if(ok)
                        cout << "Ordering is possible.";
                else
                        cout << "The door cannot be opened.";
                cout << endl;
        }

        return 0;
}

