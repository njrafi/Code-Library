/*

in a Dag, every node except the root has  dominators. ( can have multiple)

Dominator of a node means if we delete the dominator the node will be disconnected from the root

aste aste tree banabo

1st e root k add korbo tree te

jar parent ektai she tar sorasori dominator

nahole parent der lca dominator

node gula process korte hobe top sort onujayi

*/


/// Implemented from niloy vai video

namespace dom
{

#define mxn 100005


bool taken[mxn];
/// tot node , root
int n,root;
/// main graph ulta edge
vi v[mxn];
/// after topology sort
vi topo;
/// p[x][y] means 2^y th parent of x
int p[mxn][22];
/// The dominator tree
vi tree[mxn];
/// Level of the node in tree
int l[mxn];


/// dfs for topSort
void dfs(int u)
{
        if(!taken[u])
        {
                For(i,v[u].sz)
                        dfs(v[u][i]);
                topo.pb(u);
                taken[u] = 1;
        }
}


/// Update lca for u
void update_lca(int u)
{
        for(int j = 1 ; ( 1 << j) < n ; j++)
                if(p[u][j-1]!=-1)
                        p[u][j] = p[p[u][j-1]][j-1];
}


int get_lca(int uu,int vv)
{
        if(l[uu]<l[vv])
                swap(uu,vv);

        int hi = log2(l[uu]) + 2;

         // bring both node to same level
        for(int i = hi ; i >= 0 ; i--)
                if(l[uu] - (1<<i) >= l[vv])
                        uu = p[uu][i];

        if(uu==vv)
                return uu;

        for(int i = hi ; i >= 0 ; i--)
                if(p[uu][i]!=-1 && p[uu][i]!=p[vv][i])
                {
                        uu = p[uu][i];
                        vv = p[vv][i];
                }

        return p[uu][0];
}

void init()
{
        mem(taken,0);
        mem(p,-1);

        /// top sort
        Fre(i,1,n+1)
                dfs(i);

        /// remember to change for diff problems
        root = 1;
        l[root] = 0;


        /// Processing nodes
        For(i,topo.sz)
        {
                int u = topo[i];
                if( u == root)
                        continue;
                int par;

                if(v[u].sz==1)
                        par = v[u][0];
                else
                {
                        par = get_lca(v[u][0],v[u][1]);

                        Fre(j,2,v[u].sz)
                                par = get_lca(par,v[u][j]);
                }


                cout << par << " " << u << endl;
                tree[par].pb(u);
                l[u] = l[par] + 1;
                p[u][0] = par;
                update_lca(u);
        }




}




}



/*
7 10
1 2
1 3
2 3
2 4
2 6
6 4
3 4
3 7
4 7
4 5
*/


int main()
{

        int n,m,a,b;
        sff(n,m);
        while(m--)
        {
                sff(a,b);
                dom::v[b].pb(a);
        }
        dom::n = n;
        dom::init();













        return 0;
}


