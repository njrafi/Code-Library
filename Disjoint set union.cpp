
#define mxn 1002

int uf[mxn];


void ini()
{
    For(i,n)
        uf[i] = i;
}

int find(int u) 
{
    if (u == uf[u]) return u;
    return uf[u] = find(uf[u]);
}

void merge(int u, int v) 
{
    uf[find(v)] = find(u);
}
