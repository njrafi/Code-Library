/*
Kosaraju Algo:

1.  topsort the graph using dfs ( in this algo the method is slighly different.
    normal topsort e ekta element nite na parle ja ja neoa lagbe nia 
    taken[element] = 1 korte hoy kntu eikhane agei
    taken[element] = 1 kore ki ki neoa lagbe dekhte hobe.

2.  toposort er element gula 'top' vector e nibo

3.  top vector k reverse kore proti element e dfs chalabo jodi visited na hoy.
    protibar dfs e jara visit hobe tara ek ekta SCC r bolai jay 
    joto bar dfs chalano lagbe totota SCC ache.

extra 1 : ekta SCC te ektar beshi element thaka mane graph e cycle ache.
extra 2 : SCC == nodes na hole cycle ache graph e . so topsort somvob na .

*/


#define mxn 50005


vi v[mxn],vt[mxn],top,vv[mxn];
vpi edge;
int vis[mxn],com[mxn] , sccsz[mxn] , sccmn[mxn];
int tot;               
int in[mxn],out[mxn]; 

/*
// v main graph,vt transpose graph;
// vv contains edge between scc's
// edge cotains the edges
// sccsz contains the size of ith scc
// sccmn contains the minimum node of ith scc
// vv contains edge between scc's
// com cotains the which scc a node belongs
// tot = number of SCC
// indegree and outdegree of a SCC

*/
  
/// Topology sort for Kosaraju
void topo(int s)
{

        vis[s] = 1;
        For(i,v[s].sz)
                if(!vis[v[s][i]])
                        topo(v[s][i]);

        top.pb(s);

}

/// 2nd dfs for Kosaraju
void dfs(int s,int val)
{
        vis[s] = 1;
        com[s] = val;

        For(i,vt[s].sz)
                if(!vis[vt[s][i]])
                        dfs(vt[s][i],val);
}


void ini()
{
                mem(v,NULL);
                mem(vt,NULL);
                edge.clr;
                top.clr;
                mem(vis,0);
                For(i,mxn)
                        sccmn[i] = inf;
                mem(vv,NULL);
                mem(sccsz,0);
                tot = 1;
}

int main()
{

        int t,n,m,a,b,cs = 1;
        sf(t);
        while(t--)
        {
                ini();

                sf(n);

                For(i,n)
                {
                        sff(a,b);
                        edge.pb(mp(a,b));
                        v[a].pb(b);
                        vt[b].pb(a);
                }


                /// Doint topo sort
                Fre(i,1,n+1)
                        if(!vis[i])
                                topo(i);

                /// reversing top 
                reverse(all(top));

                mem(vis,0);


                /// 2nd dfs
                For(i,top.sz)
                        if(!vis[top[i]])
                                dfs(top[i],tot++);

               
                Fre(i,1,n+1)
                {
                        /// Getting size and minimum
                        sccsz[com[i]]++;
                        sccmn[com[i]] = min(sccmn[com[i]],i);
                       
                }
               
                mem(in,0);
                mem(out,0);

                For(i,edge.sz)
                {
                        a = edge[i].ff;
                        b = edge[i].ss;
                        if(com[a]!=com[b])
                        {

                                // Building scc graph

                                vv[com[a]].pb(com[b]);
                                out[com[a]] = 1;
                                in[com[b]] = 1;
                        }
                }

        }
        return 0;
}
