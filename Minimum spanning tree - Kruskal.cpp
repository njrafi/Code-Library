
#define mxn 5005

vector< pair < int , pii > > v;                
int a[mxn];                                     


void ini(int n)                                 
{
        For(i,n+1)
                a[i] = i;
}

int root(int u)                                  
{
       if(u==a[u]) return u;
       return a[u] = root(a[u]);
}


void uni(int x,int y)                            
{
        a[root(x)] = root(y);
}

int kruskal()                                   
{

        sort(all(v));
        int ans = 0;
        For(i,v.sz)
                if(root(v[i].ss.ff)!=root(v[i].ss.ss))          //finding cycle
                {
                        ans += v[i].ff;
                        uni(v[i].ss.ff,v[i].ss.ss);
                }
        return ans;
}

