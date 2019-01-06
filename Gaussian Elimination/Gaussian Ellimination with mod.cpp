
i64 bigmod(i64 num,i64 n,i64 mod)
{
        if(n==0)
                return 1;
        i64 x = bigmod(num,n/2,mod);
        x = x * x % mod;
        if( n % 2 == 1)
                x = x * num % mod ;
        return x;
}

i64 modinverse(i64 num,i64 mod)
{
        return bigmod(num,mod-2,mod) % mod ;
}


i64 a[105][100];           // contains the coeff,ans included
int node , k;
int where[105];
vi v[105];


i64 calc()
{
        i64 pp = 0;
        For(i,node)
                if(where[i]==-1)
                        pp++;

        return bigmod(k,pp,1000000007);
}

i64 gauss ()
{
        int n = node;            // row size
        int m = node;           // col size

        mem(where,-1);        // where[i] = -1 , row i zero, var i independent
        for (int col=0, row=0; col<m && row<n; ++col)
        {
                int sel = row;
                if(!a[sel][col])
                {
                        for (int i = row; i<n; ++i)
                                if (a[i][col] > a[sel][col])
                                {
                                        sel = i;
                                        break;
                                }
                }


                if ( !a[sel][col])              // col zero of
                        continue;


                for (int i = col; i <= m ; ++i)
                        swap (a[sel][i], a[row][i]);
                where[col] = row;

                for (int i=row+1; i<n; ++i)
                {

                        i64 c = ( a[i][col] * modinverse(a[row][col],k) ) % k;
                        for (int j=col; j<=m; ++j)
                                a[i][j] = (a[i][j] - ( a[row][j] * c) % k  + k ) % k;
                }
        ++row;
        }
        for (int i=0; i<m; ++i)
                if (where[i] == -1 && a[i][m] )
                                return 0;


        for (int i=0; i<m; ++i)
                if (where[i] == -1)
                        return calc();
        return 1;
}


void a_calc()
{
        For(i,node)
        {
                a[i][i] = (-1 + k) % k;

                For(j,v[i].sz)
                {
                        int tem = v[i][j];
                        a[i][tem] = 1;
                }
        }

}
int main()
{

        int t , m , cs = 1 , x,  y;
        sf(t);
        while(t--)
        {
                mem(v,NULL);
                mem(a,0);
                sfff(node,m,k);

                while(m--)
                {
                        sff(x,y);
                        x--;
                        y--;
                        v[x].pb(y);
                        v[y].pb(x);
                }

                a_calc();

                CASE(cs++);

                printf("%lld\n",gauss());
        }

        return 0;
}

