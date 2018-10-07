/*

If we know a polynomial of n degree
we cant get f(x) for n numbers of different x
and then compute f(x) for any x precisely



*/

i64 f(int n)
{

        i64 ans = 0;
        Fre(i,1,n+1)
                Fre(j,1,n+1)
                        Fre(k,1,n+1)
                                Fre(l,1,n+1)
                                        Fre(m,1,n+1)
                                        {
                                                i64 tem = 1;
                                                tem *= abs(i-j);
                                                tem *= abs(j-k);
                                                tem *= abs(k-l);
                                                tem *= abs(l-m);
                                                tem *= abs(m-i);
                                                tem %= mod;
                                                ans += tem;
                                                ans %= mod;
                                        }
        return ans;
}

i64 val[25];

/// sample points
/// should be greater or equal to degree of polynomial
int k;

i64 ff(int n)
{
        i64 ans = 0;

        Fre(i,1,k+1)
        {
                i64 tem = 1;
                Fre(j,1,k+1)
                        if(i!=j)
                        {

                                tem *= (n - j);
                                tem += mod;
                                tem %= mod;
                                tem *= modinverse(i - j + mod);
                                tem %= mod;
                        }
                ans += val[i]*tem;
                ans %= mod;
        }

        return ans;
}
int main()
{
//        WRITE;
        int n;
        k = 11;
        Fre(i,1,k+1)
                val[i] = f(i);


        while(cin >> n && n)
                cout << ff(n) << endl;













        return 0;
}


