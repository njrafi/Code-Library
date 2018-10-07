

/// Modified bigmod , add , multiply function
/// for mod > 10 ^ 9

i64 addmod(i64 x,i64 y,i64 m )
{
        x %= m;
        y %= m;
        i64 sum = x+y-m; // -m <= sum < m-1
        if(sum<0)
                sum += m;
        return sum;
}


/// gives (x*y)%m in O(64)
i64 mulmod(i64 x,i64 y,i64 m )    
{

        x %= m;
        y %= m;
        if(x>y)
                swap(x,y);

        i64 product = 0;
        for (; x != 0; x >>= 1, y = addmod(y,y,m) )
                if (x&1)
                        product = addmod(product,y,m);
        return product;
}

i64 bigmod(i64 num,i64 n,i64 M)
{
        if(n==0)
                return 1;
        i64 x= bigmod(num,n/2,M);
        x = mulmod(x,x,M);
        if(n%2==1)
                x = mulmod(x,num,M);
        return x;
}


int main()
{


        int t,cs = 1;
        i64 a,b,c;
        sf(t);
        while(t--)
        {
                scanf("%lld %lld %lld",&a,&b,&c);
                CASE(cs++);
                printf("%lld\n",bigmod(a,b,c));
        }

        return 0;
}

