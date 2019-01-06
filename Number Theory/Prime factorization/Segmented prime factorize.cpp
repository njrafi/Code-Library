/// prime factorize all number in a range[a,b]
/// Range length is smaller than  10 ^ 5 


#define lim 1000106
/// must be greater than sqrt(b)


bool isp[lim];
/// To store primes
vector<i64> primes;


vector<pair<i64,i64> > pref[1000055];

i64 a,b,lat[100005];


/// generating primes

void sieve()
{
        int up = sqrt(lim);
        Fre(i,2,up)
                if(!isp[i])
                        for( int j = i * i ; j < lim ; j += i)
                                isp[j] = 1;
        Fre(i,2,lim)
                if(!isp[i])
                        primes.pb(i);
}



/// main algo

void sieve2()
{

        Fre(i,a,b+1)
                lat[i-a] = i;
        for(int i = 0 ; primes[i]*primes[i]<=b ; i++)
        {
                i64 gg = a/primes[i];
                while(gg*primes[i]<a)
                        gg++;

                for(i64 j = gg * primes[i] ; j<=b ; j+= primes[i])
                {

                        pref[j-a].pb(mp(primes[i],0));

                        while(lat[j-a] % primes[i]==0)
                        {
                                lat[j-a] /= primes[i];
                                pref[j-a].back().ss++;
                        }
                }

        }

        Fre(i,a,b+1)
                if(lat[i-a]>1)
                        pref[i-a].pb(mp(lat[i-a],1));
}

int main()
{


        cin >> a >> b;
        sieve();
        sieve2();

        for(int i = a ; i <= b ; i++)
        {
                cout << i << " ::::" << endl;

                For(j,pref[i-a].sz)
                        cout << pref[i-a][j].ff << " " << pref[i-a][j].ss << endl;


                cout << endl << endl  ;
        }


        return 0;
}

