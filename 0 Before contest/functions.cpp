
i64 gcd(i64 a,i64 b)
{
	if(!b)
		return a;
	return gcd(b,a%b);
}

i64 bigmod(i64 num,i64 n)
{
        num %= mod;
	if(n==0)
		return 1;
	i64 x = bigmod(num,n/2);
	x = x * x % mod;
	if(n%2==1)
		x = x * num % mod;
	return x;
}

i64 modinverse(i64 num)
{
	return bigmod(num,mod-2)%mod;
}

i64 po(i64 a,i64 b)
{
	i64 ans=1;
	while(b--)
		ans *= a;
	return ans;
}

i64 ncr(i64 n,i64 r)
{
	if(r>n)
		return 0;
	if(n==r || !r)
		return 1;
	if(r==1)
		return n;

	return ncr(n-1,r) + ncr(n-1,r-1);
}






