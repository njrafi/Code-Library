
#define mxn 1000006

vi v;
pii tree[4 * mxn];
int dir[mxn];
int f[mxn];
int st;


void update(int n,int st,int en,int idx,int val,int id)
{
        if(st==en)
        {
                tree[n] = mp(val,id);
                return;
        }

        int mid = (st+en)/2 , lc = 2 * n , rc = lc + 1;

        if(idx<=mid)
                update(lc,st,mid,idx,val,id);
        else
                update(rc,mid+1,en,idx,val,id);

        if(tree[lc].ff>=tree[rc].ff)
                tree[n] = tree[lc];
        else
                tree[n] = tree[rc];
}


pii query(int n,int st,int en,int l,int r)
{
        if(en<l || r<st)
                return mp(0,v.sz);
        if(l<=st && en<=r)
                return tree[n];
        int mid = (st+en)/2 , lc = 2 * n , rc = lc + 1;

        pii q1 = query(lc,st,mid,l,r);
        pii q2 = query(rc,mid+1,en,l,r);

        if(q1.ff>=q2.ff)
                return q1;
        return q2;

}



int lissize()
{
        int ans = 0;


        for(int i = v.sz -1 ; i>=0 ; i--)
        {
                // remove the plus one if u want non decreasing


                pii mx = query(1,1,mxn,v[i]+1,mxn);
                f[i] = 1 + mx.ff;


                if(mx.ff)
                        dir[i] = mx.ss;
                else
                        dir[i] = v.sz;

                if(f[i]>ans)
                {
                        ans = f[i];
                        st = i;
                }
                update(1,1,mxn,v[i],f[i],i);

        }

        return ans;
}


void print(int pos)
{

        if(pos==v.sz)
                return;
        pfs(v[pos]);

        print(dir[pos]);
}

int main()
{

        // if the input limit is more than 10^5 map the inputs
        // careful with the limit , after mapping mxn should be 2*n

        int n , inp;
        sf(n);
        while(n--)
        {
                sf(inp);
                v.pb(inp);
        }

        pfn( lissize() );

        print(st);






        return 0;
}

