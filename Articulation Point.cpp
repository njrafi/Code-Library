/*
The idea is to use DFS. In DFS, we follow vertices in tree form called DFS tree.

In DFS tree, a vertex u is parent of another vertex v,
if v is discovered by u (obviously v is an adjacent of u in graph).

In DFS tree, a vertex u is articulation point if one of the following two conditions is true.
1) u is root of DFS tree and it has at least two children.
2) u is not root of DFS tree and it has a child v such that no vertex in subtree rooted with v has a back edge to one of the ancestors (in DFS tree) of u.

We do DFS traversal of given graph with additional code to find out Articulation Points (APs).
In DFS traversal, we maintain a parent[] array where parent[u] stores parent of vertex u.
Among the above mentioned two cases, the first case is simple to detect.
For every vertex, count children.
If currently visited vertex u is root (parent[u] is NIL) and has more than two children, print it.
How to handle second case? We maintain an array disc[] to store discovery time of vertices. 
For every node u, we need to find out the earliest visited vertex (the vertex with minimum discovery time) 
that can be reached from subtree rooted with u.
So we maintain an additional array low[] which is defined as follows.

low[u] = min(disc[u], disc[w]) 
where w is an ancestor of u and there is a back edge from 
some descendant of u to w.

*/
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

