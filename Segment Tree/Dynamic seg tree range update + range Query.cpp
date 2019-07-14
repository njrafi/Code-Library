
struct node {
        node *l,*r;
        i64 sum,lazy;

        node() {
                l = r = nullptr;
                sum = lazy = 0;
        }

        node(i64 st,i64 en)
        {
                l = r = nullptr;
                sum = ( en * (en + 1) ) / 2 - ( st * (st-1))/2;
                lazy = 0;
        }

};


void process(node *n,i64 st,i64 en,i64 val)
{
        n->sum -= val * (en-st+1);
        n->lazy = 0;
        i64 mid = (st+en)/2;
        if(st != en)
        {
                if( n->l == nullptr) n->l = new node(st,mid);
                if( n->r == nullptr) n->r = new node(mid+1,en);
                n->l->lazy += val;
                n->r->lazy += val;
        }
}


void update(node *n,i64 st,i64 en,i64 l,i64 r,i64 val)
{
        if ( n->lazy)
                process(n,st,en,n->lazy);

        if( en < l || r < st) return;

        if(l <= st && en <=r)
        {
                process(n,st,en,val);
                return;
        }

        i64 mid = (st+en)/2;

        if( n->l == nullptr) n->l = new node(st,mid);
        if( n->r == nullptr) n->r = new node(mid+1,en);

        update(n->l,st,mid,l,r,val);
        update(n->r,mid+1,en,l,r,val);

        n->sum = n->l->sum + n->r->sum;

}



i64 query(node *n,i64 st,i64 en,i64 l,i64 r)
{
        if ( n->lazy)
                process(n,st,en,n->lazy);

        if( en < l || r < st) return 0;

        if(l <= st && en <=r)
                return n->sum;

        i64 mid = (st+en)/2;

        if( n->l == nullptr) n->l = new node(st,mid);
        if( n->r == nullptr) n->r = new node(mid+1,en);

        return query(n->l,st,mid,l,r) + query(n->r,mid+1,en,l,r);

}



int main()
{
        int n,q;
        sff(n,q);
        node *root = new node(1,n);
        while(q--)
        {
                int op,l,r,val;
                sfff(op,l,r);
                if(op == 2)
                        printf("%lld\n", query(root,1,n,l,r));
                else
                {
                        sf(val);
                        update(root,1,n,l,r,val);
                }
        }


        return 0;
}


