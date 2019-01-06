


vi f(int n)
{
	vi v;

	for(int i = 2 ; i * i <=n ; i++)
		if(n%i==0)
		{
			v.pb(0);
			while(n%i==0)
			{
				v.back()++;
				n /= i;
			}
		}

	if(n>1)
		v.pb(1);

	return v;
}
int main()
{


//        WRITE;
	int n,m,t,cs = 1 ;
	while(1)
	{
		sfff(n,m,t);

		if(!n && !m && !t)
			break;

		vi v = f(n);

                i64 k = 1 , k1 = 1;

                For(i,v.sz)
                {
                        k *= ( ((i64)v[i]*m) / t + 1);
                        k %= mod;
                        k1 *= ( ((i64)v[i]*m) / (t+1) + 1);
                        k1 %= mod;
                }


                CASE(cs++);

                cout << ( k - k1 + mod) % mod << endl;
	}




	return 0;
}

