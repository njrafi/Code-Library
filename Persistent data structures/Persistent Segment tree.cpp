
#define mxn 100005

int gg;
int v[mxn];

struct node
{
        int lc,rc,val;
};

node tree[80 * mxn];

void build(int now,int st,int en)
{
        if(st==en)
        {
                tree[now].val = v[st];
                return;
        }

        tree[now].lc = gg++;
        tree[now].rc = gg++;

        int mid = (st+en)/2 , lc = tree[now].lc , rc = tree[now].rc;

        build(lc,st,mid);
        build(rc,mid+1,en);

        tree[now].val = tree[lc].val + tree[rc].val;
}


// prev is for the version we are modifying from
void update(int now,int prev,int st,int en,int idx,int val)     
{
        if(st==en)
        {
                tree[now].val = tree[prev].val + val;
                return;
        }

        int mid = (st+en)/2;

        if(idx<=mid)
        {
                tree[now].lc = gg++;
                tree[now].rc = tree[prev].rc;
                update(tree[now].lc,tree[prev].lc,st,mid,idx,val);
        }
        else
        {
                tree[now].lc = tree[prev].lc;
                tree[now].rc = gg++;
                update(tree[now].rc,tree[prev].rc,mid+1,en,idx,val);
        }

        tree[now].val = tree[tree[now].lc].val + tree[tree[now].rc].val;

}

int query(int now,int st,int en,int l,int r)
{
        if(en < l  || r < st)
                return 0;
        if(l<=st && en<=r)
                return tree[now].val;

        int mid = (st+en)/2 , lc = tree[now].lc , rc = tree[now].rc;

        int q1 = query(lc,st,mid,l,r);
        int q2 = query(rc,mid+1,en,l,r);

        return q1+q2;
}


int main()
{

        gg = 2;         // As first root is 1

        int n , l ,r ,idx, val ,q , op , prev;
        sf(n);
        Fre(i,1,n+1)
                sf(v[i]);
        build(1,1,n);


        sf(q);
        vi roots;
        roots.pb(1);
        while(q--)
        {

                sf(op);
                if(op==1)
                {

                        // whenever we need update
                        int newroot = gg++;
                        sfff(prev,idx,val);
                        update(newroot,roots[prev],1,n,idx,val);
                        roots.pb(newroot);
                }
                else
                {
                        sfff(prev,l,r);
                        pfn(query(roots[prev],1,n,l,r));
                }
        }

        return 0;
}
