
#define mxn 100005

vi v[mxn] , w[mxn];
int p[mxn][22],root,n;
int l[mxn];             // level
int mn[mxn][22];
int tot[mxn][22];
i64 total;
int pathsize ;

// p[x][y] means 2^y th parent of x
// mn[x][y] means the min edge in the path of 2^y th parent
// tot[x][y] means the total cost in the path of 2^y th parent
// pathsize will give us the number of edges between u and v

void input()
{
        int a,b , c;
        mem(v,NULL);
        mem(w,NULL);

        root = 1;

        sf(n);
        For(i,n-1)
        {
                sfff(a,b,c);
                v[a].pb(b);
                v[b].pb(a);
                w[a].pb(c);
                w[b].pb(c);
        }
}

// determing the level of the nodes
void dfs(int s,int par,int lev,int  pedge)                
{
        p[s][0] = par;
        mn[s][0] = pedge;
        tot[s][0] = pedge;

        l[s] = lev;
        For(i,v[s].sz)
                if(l[v[s][i]]==-1)
                        dfs(v[s][i] , s , lev+1 , w[s][i] );
}

void gen_table()
{
        mem(p,-1);
        mem(l,-1);
        dfs(root,-1,0,inf);
        // (1<<j) = po(2,j)
        for(int j = 1 ; (1<<j) < n ; j++)                
            Fre(i,1,n+1)
                if(p[i][j-1]!=-1)
                {
                    p[i][j] = p[p[i][j-1]][j-1];
                    mn[i][j] = min(mn[p[i][j-1]][j-1] , mn[i][j-1]);
                    tot[i][j] = tot[p[i][j-1]][j-1] +  tot[i][j-1];
                }



}


// gives us lca , min cost edge , total cost , pathsize
pii query(int uu,int vv)                
{
        if(l[uu]<l[vv])
                swap(uu,vv);

        int hi = log2(l[uu]) + 2;
        int mnn = inf;
        total = 0;
        pathsize = 0;

         // bring both node to same level
        for(int i = hi ; i >= 0 ; i--)                 
                if(l[uu] - (1<<i) >= l[vv])
                {
                        mnn = min( mn[uu][i] , mnn);
                        total += tot[uu][i];
                        pathsize += (1<<i);
                        uu = p[uu][i];
                }

        if(uu==vv)
                return mp(uu , mnn);


        for(int i = hi ; i >= 0 ; i--)
                if(p[uu][i]!=-1 && p[uu][i]!=p[vv][i])
                {

                        mnn = min( mn[uu][i] , mnn);
                        total += tot[uu][i];
                        uu = p[uu][i];

                        mnn = min( mn[vv][i] , mnn);
                        total += tot[vv][i];
                        vv = p[vv][i];

                        pathsize += (1<<i);
                        pathsize += (1<<i);

                }

        pathsize += 2;
        mnn = min( mnn ,  min ( mn[uu][0] , mn[vv][0]) );
        total += tot[uu][0] + tot[vv][0];

        return mp(p[uu][0],mnn);
}

int main()
{



        input();
        gen_table();
        int q,a,b;
        sf(q);
        For(i,q)
        {
                sff(a,b);
                pii ans = query(a,b);
                cout << total - ans.ss * pathsize << endl;
        }
        return 0;
}

