

///  to calculate ( a ^ ( b ^ n ) ) % p
// p prime number, a and p co prime

i64 fermat(i64 a,i64 b,i64 n,i64 p)
{
        return bigmod(a , bigmod( b, n, p-1) , p) ;
}

int main()
{


        i64 a,b,p,n;
        while(cin >> a >> b >> n >> p)
                cout << fermat(a,b,n,p) << endl;

        return 0;
}

