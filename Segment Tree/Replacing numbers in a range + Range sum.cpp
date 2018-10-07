
#define mxn 100005

vi v[mxn];
pii id[mxn];
int tree[4 * mxn] , ti , lazy[4 * mxn];

void dfs(int u)
{
        ti++;
        id[u].ff = ti;

        For(i,v[u].sz)
                dfs(v[u][i]);

        id[u].ss = ti;
}

void build(int n,int st,int en)
{
        if(st==en)
        {
                tree[n] = 1;
                return;
        }

        int mid = (st+en)/2 , lc = 2 * n , rc = lc + 1;

        build(lc,st,mid);
        build(rc,mid+1,en);

        tree[n] = tree[lc] + tree[rc];
}

void process(int n,int st,int en,int val)
{
        tree[n] = (en-st+1) * val;
        lazy[n] = -1;
        int lc = 2 * n, rc = lc + 1;

        if(st!=en)
        {
                lazy[lc] = val;
                lazy[rc] = val;
        }
}


void update(int n,int st,int en,int l,int r,int val)
{
        if(l>r)
                return;
        if(lazy[n]!=-1)
                process(n,st,en,lazy[n]);

        if(st>en || en<l || st>r)
                return;

        if(l<=st && en<=r)
        {
                process(n,st,en,val);
                return;
        }
        int mid = (st+en)/2 , lc = 2 *n  , rc = lc  + 1;

        update(lc,st,mid,l,r,val);
        update(rc,mid+1,en,l,r,val);

        tree[n] = tree[lc] + tree[rc];
}

int query(int n,int st,int en,int l,int r)
{
        if(l>r)
                return 0;
        if(lazy[n]!=-1)
                process(n,st,en,lazy[n]);

        if(st>en || en<l || st>r)
                return 0;

        if(l<=st && en<=r)
                return tree[n];

        int mid = (st+en)/2 , lc = 2 * n , rc  = lc + 1;

        int p1 = query(lc,st,mid,l,r);
        int p2 = query(rc,mid+1,en,l,r);

        return p1 + p2;


}

int main()
{

        //ios_base::sync_with_stdio(false);cin.tie(0);
        int n,q,op,inp;

        fastRead(&n);

        Fre(i,1,n+1)
        {
                fastRead(&inp);
                v[inp].pb(i);
        }

        dfs(0);
        build(1,1,n+1);
        mem(lazy,-1);
        sf(q);

        while(q--)
        {
                fastRead(&op);
                fastRead(&inp);
                int l = id[inp].ff;
                int r = id[inp].ss;

                if(op==1)
                        update(1,1,n+1,l+1,r,1);
                else if(op==2)
                        update(1,1,n+1,l+1,r,0);
                else
                        fastWrite(query(1,1,n+1,l+1,r));
        }






        return 0;
}

