
#define mxn 1005

vi edge[mxn],ans;
bool taken[mxn];


void dfs(int p)
{
        if(!taken[p])
        {
                For(i,edge[p].sz)
                        dfs(edge[p][i]);
                ans.pb(p);
                taken[p] = 1;
        }
}

int main()
{
        int m;
        cin >> m;
        while(m--)
        {
                cin >> a >> b;
                edge[b].pb(a);
        }

        Fre(i,1,n+1)
                dfs(i);

        For(i,ans.sz)
                cout << ans[i] << " ";

    

        return 0;
}

