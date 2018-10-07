
#define maxn 5000006

bool prime[maxn];
unsigned long long int cum[maxn];
int phi[maxn];

void sievephi(int n)
{
        For(i,n)
        {
                prime[i] = 1;
                phi[i] = i;
        }

        prime[0] = prime[1] = 0;

        Fre(i,2,n)
                if(prime[i])
                        for(int j=i;j<n;j+=i)
                        {
                                prime[j] = 0;
                                phi[j] = (phi[j]/i)*(i-1);
                        }

        For(i,n-1)
                cum[i+1] = (i64)phi[i] + cum[i];
}

