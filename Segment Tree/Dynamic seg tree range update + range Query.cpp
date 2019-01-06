
struct node
{
        i64 cnt,lazy;
        node *l,*r;
        node()
        {
                l = nullptr;
                r = nullptr;
                cnt = 0;
                lazy = 0;
        }

        node(i64 st,i64 en)
        {
                l = nullptr;
                r = nullptr;
                cnt = (en * (en+1)) / 2 - (st * (st-1)) / 2;
                lazy = 0;
        }
};



void process(node *n,int st,int en,i64 val)
{
        n->cnt -= val * (en-st+1);
        n->lazy = 0;

        int mid = (st+en)/2;

        if(st!=en)
        {
                if( n->l == nullptr) n->l = new node(st,mid);
                n->l->lazy += val;

                if( n->r == nullptr) n->r = new node(mid+1,en);
                n->r->lazy += val;

        }
}



void update(node *n,int st,int en,int l,int r,i64 val)
{

        if(n->lazy)
                process(n,st,en,n->lazy);

        if(r < st || en < l) return;

        if(l<=st && en<=r)
        {
                process(n,st,en,val);
                return;
        }

        int mid = (st+en)/2;


        if( n->l == nullptr) n->l = new node(st,mid) ;
        update(n->l , st , mid , l, r , val);


        if( n->r == nullptr) n->r = new node(mid+1,en);
        update( n->r , mid + 1 , en , l , r , val );


        n->cnt = 0;

        n->cnt += n->l->cnt;
        n->cnt += n->r->cnt;

}


i64 sum(node *n,int st,int en,int l,int r)
{
        if(n->lazy)
                process(n,st,en,n->lazy);

        if(r < st || en < l) return 0;
        if(l <= st && en <= r)
                return n->cnt;

        int mid = (st+en)/2;

        i64 ret = 0;

        if( n->l == nullptr) n->l = new node(st,mid);
        ret += sum(n->l , st , mid , l , r);


        if( n->r == nullptr) n->r = new node(mid+1,en);
        ret += sum(n->r , mid + 1 , en , l , r);

        return ret;

}


int main()
{
        int n,q,op,l,r,inp;
        sff(n,q);
        node *root = new node(1,n);

        while(q--)
        {
                sf(op);
                if(op==2)
                {
                        sff(l,r);
                        printf("%lld\n",sum(root,1,n,l,r));
                }
                else
                {
                        sfff(l,r,inp);
                        update(root,1,n,l,r,inp);
                }
        }

        return 0;
}


