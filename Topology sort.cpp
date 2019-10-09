#define mxn 100005



// Initialize all
bool taken[mxn], processing[mxn];
bool cycle;
vector<int> ans;
vector<int> v[mxn];

void dfs(int node)
{

    if (processing[node])
    {
        cycle = 1;
        return;
    }
    if (taken[node])
        return;
    processing[node] = 1;
    For(i,v[node].sz)
    {
        int vv = v[node][i];
        dfs(vv);
    }
    taken[node] = 1;
    processing[node] = 0;
    ans.pb(node);
}



int main()
{
    int m;
    cin >> m;
    while (m--)
    {
        cin >> a >> b;
        v[b].pb(a);
    }

    Fre(i, 1, n + 1)
        dfs(i);

    For(i, ans.sz)
            cout << ans[i] << " ";

    return 0;
}