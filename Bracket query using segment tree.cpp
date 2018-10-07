

// In a range [l,r] max correct bracket subsequence

#define mxn 1000006

struct node
{
        int mx,op,cl;
};

node make_node(int a,int b,int c)
{
        node tem;
        tem.mx = a;
        tem.op = b;
        tem.cl = c;
        return tem;
}

node merg(node l,node r)
{
        int mn = min(l.op,r.cl);
        node tem;
        tem.mx = l.mx + r.mx +  2 * mn;
        tem.op = l.op + r.op - mn;
        tem.cl = l.cl + r.cl - mn;

        return tem;
}

node tree[4 * mxn];
string s;


void build(int n,int st,int en)
{
        if(st==en)
        {
                if(s[st-1]=='O')
                        tree[n] = make_node(0,1,0);
                else
                        tree[n] = make_node(0,0,1);

                return;
        }

        int mid = (st+en) / 2, lc = 2*n, rc = lc + 1;

        build(lc,st,mid);
        build(rc,mid+1,en);

        tree[n] = merg(tree[lc],tree[rc]);
}

void update(int n,int st,int en,int idx)
{
        if(st==en)
        {
                if(s[st-1]=='C')
                {

                        s[st-1] = 'O';
                        tree[n] = make_node(0,1,0);
                }
                else
                {

                        s[st-1] = 'C';
                        tree[n] = make_node(0,0,1);
                }

                return;
        }

        int mid = (st+en) / 2, lc = 2*n, rc = lc + 1;

        if(idx<=mid)
                update(lc,st,mid,idx);
        else
                update(rc,mid+1,en,idx);

        tree[n] = merg(tree[lc],tree[rc]);
}


node query(int n,int st,int en,int l,int r)
{
        if(en<l || r<st)
                return make_node(0,0,0);
        if(l<=st && en<=r)
                return tree[n];

        int mid = (st+en) / 2, lc = 2*n, rc = lc + 1;

        return merg(query(lc,st,mid,l,r),query(rc,mid+1,en,l,r));
}



int main()
{

        cin >> s;

        build(1,1,s.sz);

        int q,l,r;
        string op;
        cin >> q;
        while(q--)
        {
                cin >> op;
                if(op=="Q")
                {
                        cin >> l >> r;
                        cout << query(1,1,s.sz,l,r).mx << endl;
                }
                else
                {

                        cin >> l;
                        update(1,1,s.sz,l);
                }
        }

        return 0;
}

