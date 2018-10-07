
// dont know how this works
// But the complexity is sqrt(n)
// Give us summation of sod(i) 1<=i<=n

i64 csod(i64 n)
{
        i64 ans = 0;
        for(int i = 2; i * i <= n; ++i)
        {
                i64 j = n / i;
                ans += (i + j) * (j - i + 1) / 2;
                ans += i * (j - i);
        }
        //comment if we need sum of ACTUAL divisors

        ans += n*(n+1)/2 + n - 2;       
        return ans;
}


int main()
{

        int n;
        while(1)
        {
                sf(n);
                if(!n)
                        break;
                printf("%lld\n",csod(n));
        }

        return 0;
}

