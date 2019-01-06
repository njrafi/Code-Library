
/*
You have a string and queries of two types:
1. replace i’th character of the string by character a;
2. check if substring sj...sk is a palindrome


idea was seg tree nodes with hash and size
nodeHash = lcHash * prime ^ rcSize + rcHash
nodeSize = lcSize + rcSize

*/

#define mxn 100005
#define pr 41
ui64 pp[mxn];



/// the hash value and size
pair<ui64,int> tree[3][4 * mxn];
char s[2][mxn];


/// gg = 0 soja , gg = 1 means ulta
void update(int n,int st,int en,int idx,int val,int gg)
{
        if(st==en)
        {
                tree[gg][n] = mp(val,1);
                return;
        }

        int mid = (st + en) / 2, lc = 2 * n , rc = lc + 1;

        if(idx<=mid)
                update(lc,st,mid,idx,val,gg);
        else
                update(rc,mid+1,en,idx,val,gg);

        tree[gg][n].ff = tree[gg][lc].ff * pp[tree[gg][rc].ss] + tree[gg][rc].ff;
        tree[gg][n].ss = tree[gg][lc].ss + tree[gg][rc].ss;
}


pair<ui64,int> query(int n,int st,int en,int l,int r,int gg)
{
        if(r < st || en < l)
                return mp(0,0);

        if(l<=st && en<=r)
                return tree[gg][n];


        int mid = (st + en) / 2, lc = 2 * n , rc = lc + 1;

        pair<ui64,int> q1 = query(lc,st,mid,l,r,gg);
        pair<ui64,int> q2 = query(rc,mid+1,en,l,r,gg);
        pair<ui64,int> q;

        q.ff = q1.ff * pp[q2.ss] + q2.ff;
        q.ss = q1.ss + q2.ss;

        return q;

}



void pre(int n)
{
        pp[0] = 1;

        Fre(i,1,mxn)
                pp[i] = pp[i-1] * pr;


        For(i,n)
                update(1,1,n,i+1,s[0][i],0);

        strcpy(s[1],s[0]);

        for(int i = n - 1 , j = 0 ; i >= 0 ;i-- , j++)
                s[1][j] = s[0][i];

        For(i,n)
                update(1,1,n,i+1,s[1][i],1);
}


char op[15],cc[3];
int main()
{
        int l,r,q,n;

        scanf("%s", s[0]);
        n = strlen(s[0]);
        pre(n);


        fastRead(&q);
        while(q--)
        {
                scanf("%s",op);

                if(op[0]=='c')
                {
                        /// update call

                        fastRead(&l);
                        scanf("%s",cc);
                        r = cc[0];
                        update(1,1,n,l,r,0);

                        l = n - l + 1;

                        update(1,1,n,l,r,1);
                }
                else
                {
                        /// is palindrome?
                        fastRead(&l);
                        fastRead(&r);
                        ui64 qs = query(1,1,n,l,r,0).ff;

                        int ll = n - r + 1;
                        int rr = n - l + 1;

                        ui64 qu = query(1,1,n,ll,rr,1).ff;

                        if(qs==qu)
                                puts("Yes");
                        else
                                puts("No");
                }
        }

        return 0;
}
