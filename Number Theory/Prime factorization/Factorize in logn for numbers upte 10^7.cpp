
/*
Idea is we are storing a prime divisor for every number by sieve
then when factoring we are dividing the number by the saved factor
*/

#define mxn 5000006

i64 cum[mxn];

int spf[mxn]; // smallest prime factor of a number

void sieve()
{
        spf[1] = 1;
        Fre(i,2,mxn)
                spf[i] = i;


        for (int i=2; i*i<mxn; i++)
                if (spf[i] == i)
                        for (int j=i*i; j<mxn; j+=i)
                                if (spf[j]==j)
                                        spf[j] = i;

}

vi factors(int x)
{
        vi v;
        while (x != 1)
        {

                /// If u want distinct prime add this line
                /// if(v.empty() || v.back()!=spf[x])
                v.pb(spf[x]);
                x = x / spf[x];
        }
        return v;
}



int main()
{
       sieve();
       int n;
       while(cin >> n)
       {
               vi v = factors(n);
               For(i,v.sz)
                        cout << v[i] << " ";
                cout << endl;
       }

        return 0;
}

