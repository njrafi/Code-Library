
/// mod value
#define k 10000

int dp[k+4];
/// gives us sum of nPr(n,i) where 0 <= i <= n mod k
/// another theory is f(n) = f(n % 10^k) mod k

int f(int n)
{
        if(!n)
                return 1;
        if(dp[n]!=-1)
                return dp[n];

        return dp[n] = (1 + n * f(n-1)) % k;
}

int main()
{

        int t,cs = 1,n;
        mem(dp,-1);
        sf(t);
        while(t--)
        {
                sf(n);
                int nn = n;
                n %= k;
                CASE(cs++);
                if(nn<=6)
                        printf("%d\n",f(n));
                else
                        printf("%04d\n",f(n));
        }

        return 0;
}


