
#define mxn 505

int n;
int a[mxn][mxn];
int p2[30];
int table[mxn][32][mxn];
int lg2[mxn];



void pre()
{
        For(i,25)
                p2[i] = po(2,i);
        For(i,mxn)
                lg2[i] = log2(i);
}

void build(int gg)
{
        For(i,n)
                table[gg][0][i] = a[gg][i];

        for(int j = 1 ; p2[j] <= n ; j++)
                for(int i = 0 ; i + p2[j-1] < n ; i++)
                        table[gg][j][i] = max(table[gg][j-1][i] , table[gg][j-1][i+p2[j-1]]);

}

int query(int gg,int l,int r)
{
        int len = r - l + 1;
        int k = lg2[len];
        return max(table[gg][k][l],table[gg][k][r+1-p2[k]]);
}

int main()
{

        int m,t,l,r,gg , cs = 1;
        pre();
        fastRead(&t);

        while(t--)
        {
                fastRead(&n);
                fastRead(&m);

                For(i,n)
                        For(j,n)
                                fastRead(&a[i][j]);

                For(i,n)
                        build(i);

                CASE(cs++);
                while(m--)
                {
                        fastRead(&l);
                        fastRead(&r);
                        fastRead(&gg);
                        l--;
                        r--;
                        int ll = l + gg - 1;
                        int rr = r + gg - 1;
                        int ans = -inf;
                        Fre(i,l,ll+1)
                                ans = max(ans, query(i,r,rr));

                        fastWrite(ans);
                }
        }

        return 0;
}

