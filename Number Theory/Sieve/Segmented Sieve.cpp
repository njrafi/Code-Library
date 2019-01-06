
#define mxn 100005
/// should be equal to sqrt(highest value)


bool prime[mxn];
vi v;

/// generating primes for segment sieve
void sieve()                           
{
        mem(prime,0);
        int lim = sqrt(mxn);
        Fre(i,2,lim + 5)
                if(!prime[i])
                        for(int j = i*i ; j < mxn ; j+=i)
                                prime[j] = 1;

        Fre(i,2,mxn)
                if(!prime[i])
                        v.pb(i);

}


/// generating prime in range [a,b]
/// range length is small but both a,b can be 10 ^ 12

int seg_sieve(i64 a,i64 b)
{
        int lim = sqrt(b) + 5;
        mem(prime,0);


        /// traversing primes below sqrt(b)
        for(i64 i = 0 ; v[i]<lim ; i++)         
        {
                i64 st = (a/v[i]) * v[i];
                while(st<a || st==v[i])
                        st += v[i];  
                ///  st contains the smallest multiple of v[i] larger than a                   
                /// if the multiple is equal to the prime escape
                
                for(i64 j = st ; j <= b ; j += v[i])
                {
                        /// j is the prime
                        prime[j-a] = 1;
                }
        }

        int ans = 0;
        Fre(i,a,b+1)
                if(!prime[i-a])
                {
                        ans++;
                
                        /// here i is the prime
                }
        if(a==1)
                ans--;

        return ans;
}


int main()
{

        //cout << sqrt(pow(2,31)) << endl;
        sieve();
        int t,a,b,cs = 1;
        fastRead(&t);
        while(t--)
        {
                fastRead(&a);
                fastRead(&b);
                CASE(cs++);
                fastWrite(seg_sieve(a,b));
        }

        return 0;
}

