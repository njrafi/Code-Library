#define lim 20000000
i64 a,b,c;
i64 amc ;

i64 f(i64 x)
{
        i64 tem = (amc * x) % c;
        i64 tem2 = x % b;
        return (tem + tem2 ) % c;
}



pii floyd(i64 x)
{
        i64 tor = f(x) , hare = f(f(x));
        int cnt = 0;
        while(tor!=hare)
        {
                tor = f(tor);
                hare = f(f(hare));
                cnt++;
                if(cnt>lim)
                        return mp(lim,lim);
        }

        int mu = 0 ;
        hare = x;
        while(tor!=hare)
        {
                tor = f(tor);
                hare = f(hare);
                mu++;
        }

        int lamda = 1;
        hare = f(tor);
        while(tor!=hare)
        {
                hare = f(hare);
                lamda++;
        }

        return mp(mu,lamda);

}

// mu = 1st element of cycle
// lamda = cycle lengths

int main()
{

        READ;
        WRITE;

        cin >> a >> b >> c;
        if(a<0)
        {
                i64 tem = abs(a/c);
                tem += 1;
                amc = (a + tem * c) % c;
        }
        else
                amc = a % c;

        pii ans = floyd(1);

        if(ans.ff+ans.ss>lim)
                cout << -1;
        else
                cout << ans.ff + ans.ss << endl;


        return 0;
}

