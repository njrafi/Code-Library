
/*
Query : Max sub segment sum in a range
update: a[idx] = val
*/


#define mxn 100005

int max3(int a,int b,int c)
{
        return max(a,max(b,c));
}

struct node
{
        int ls,rs,ss,ts;        // left,right,segment,total

};

node mergegg(node ll,node rr)
{
        node res;
        res.ls = max3(ll.ls,ll.ts,ll.ts+rr.ls);
        res.rs = max3(rr.rs,rr.ts,rr.ts+ll.rs);
        res.ts = ll.ts + rr.ts;
        res.ss = max3(ll.ss,rr.ss,ll.rs+rr.ls);
        return res;
}

node tree[4*mxn];
vi v;
node gg;

void build(int n,int st,int en)
{
        if(st==en)
        {
                tree[n].ls = tree[n].rs = tree[n].ss = tree[n].ts = v[st];
                return;
        }

        int mid = (st+en)/2 , lc = 2 * n , rc = lc + 1;

        build(lc,st,mid);
        build(rc,mid+1,en);

        tree[n] = mergegg(tree[lc],tree[rc]);

}


void update(int n,int st,int en,int idx,int val)
{
        if(st==en)
        {
                tree[n].ls = tree[n].rs = tree[n].ss = tree[n].ts = val;
                return;
        }

        int mid = (st+en)/2 , lc = 2 * n , rc = lc + 1;

        if(idx<=mid)
                update(lc,st,mid,idx,val);
        else
                update(rc,mid+1,en,idx,val);

        tree[n] = mergegg(tree[lc],tree[rc]);

}




node query(int n,int st,int en,int l,int r)
{
        if(l>r || en<l || r<st)
                return gg;
        if(l<=st && en<=r)
                return tree[n];
        int mid = (st+en)/ 2 , lc = 2 * n , rc = lc + 1;

        node ll = query(lc,st,mid,l,r);
        node rr = query(rc,mid+1,en,l,r);

        node res = mergegg(ll,rr);

        return res;

}

int main()
{


        int n,inp,m,a,b,op;
        v.pb(1);

        sf(n);
        For(i,n)
        {
                sf(inp);
                v.pb(inp);
        }
        gg.ls = gg.rs = gg.ts = gg.ss = -100000;

        build(1,1,n);

        sf(m);
        while(m--)
        {
                sfff(op,a,b);
                if(op)
                        pfn(query(1,1,n,a,b).ss);
                else
                        update(1,1,n,a,b);
        }
        return 0;
}

