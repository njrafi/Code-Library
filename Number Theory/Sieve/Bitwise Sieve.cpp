
#define max_n 100000008


int v[max_n/32+2];
vi prime;


void sieve(int n)
{
        int lim = sqrt(n)+1;

        prime.clr;
        prime.pb(2);


        for(int i=3;i<=lim;i+=2)
                if(!checkbit(v[i>>5],i & 31))
                        for(int j=i*i ; j<=n; j += 2*i)
                                v[j>>5] = setbit(v[j>>5],j & 31);
        for(int i=3;i<=n;i+=2)
                if(!checkbit(v[i>>5],i & 31))
                        prime.pb(i);


}

