

i64 multimod(i64 a,i64 b,i64 m)
{
	i64 ans=0LL;
	a%=m,b%=m;
	while(b)
	{
		if(b&1LL)
			ans=m-ans>a?ans+a:ans+a-m;
		b>>=1LL;
		a=(m-a)>a?a+a:a+a-m;
	}
	return ans;
}

i64 bigmod(i64 b,i64 p,i64 m)
{
	i64 ret=1LL;
	while(p)
	{
		if( p&1LL )
			ret=multimod(ret,b,m);
		b=multimod(b,b,m);
		p>>=1LL;
	}
	return ret;
}

bool isProbablePrime(i64 n,int k)
{
	if( n<2 )
		return false;
	if( n!=2 && n%2==0)
		return false;
	if( n==2 )
		return true;
	i64 s=n-1LL;
	while(s%2==0)
		s>>=1LL;
	while(k--)
	{
		i64 a=(rand()%(n-1))+1;
		i64 tmp=s;
		i64 mod=bigmod(a,tmp,n);
		while(tmp!=n-1LL && mod!=1LL && mod!=n-1LL)
		{
			mod=multimod(mod,mod,n);
			tmp=tmp<<1LL;
		}
		if(mod!=n-1LL && tmp%2LL==0)
			return false;
	}
	return true;
}

int main()
{
	i64 n;
	Fre(i,1,100)
	if(isProbablePrime(i,5))
		cout << i << " ";
	cout << endl;
}
