/*
phi(n) = count of numbers below n that are co-prime with n

let n = p1^a1 * p1^a2 *....... * pk^ak   // prime factorization

then phi(n) = n * (1-1/p1) * (1 - 1/p2) *..... * (1- 1/pk)
*/

/// just doing prime factorization and using the sutro fro phi

i64 phi(i64 n)                  
{
        i64 ans = n;
        i64 lim = sqrt(n)+2;
        /// v[i] is primes

        for(int i=0;v[i]<lim;i++)
                if(n%v[i]==0)
                {
                        ans = ans*(v[i]-1)/v[i];
                        while(n%v[i]==0)
                                n /= v[i];
                }

        if(n>1)
                ans = ans/n*(n-1);
        return ans;
}

