/// Prime factorize for larger number

int cnt = 0;

void primefactor(i64 n)
{
      
        /// v contains primes

        vpi fact;

        for(int i = 0 ; v[i] < sqrt(n) + 2 ; i++)
                if(n%v[i]==0)
                {
                        fac.pb(mp(v[i],0));
                       
                        while(n%v[i]==0)
                        {
                                n /= v[i];
                                fac.back().ss++;
                        }
                }

        if(n>1)
                fac.pb(mp(n,1));
        
        return fact;
}

