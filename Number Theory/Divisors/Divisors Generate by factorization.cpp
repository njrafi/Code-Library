
#define mxn 3200006

bool ispr[mxn];
vi primes;

void sieve()
{
	int lim = sqrt(mxn);

	Fre(i,2,lim)
	if(!ispr[i])
		for(int j = i * i ; j < mxn ; j += i)
			ispr[j] = 1;

	Fre(i,2,mxn)
                if(!ispr[i])
}



/// getting prime divisors

vector<pair<i64,int> > get_p_div(i64 num)
{
	vector<pair<i64,int> > v;
	for(int i = 0 ; i < primes.sz && (i64)primes[i] * primes[i] <= num ; i++)
		if(num % primes[i] == 0)
		{
			v.pb(mp(primes[i],0));
			while(num % primes[i] == 0)
			{
				v.back().ss++;
				num /= primes[i];
			}
		}

	if(num>1)
		v.pb(mp(num,1));

	return v;
}

/// factors stored in a val,count way
vector<pair<i64,int> > dd;
/// to store divisors 
vector<i64> res; 



/// back Track to generate divisors
void back_t(int pos,i64 now)
{
	if(pos==dd.sz)
	{
	        if(now>1)
                        res.pb(now);
		return;
	}
	i64 tem = 1;
	For(i,dd[pos].ss+1)
	{

		back_t(pos+1, now * tem);
		tem *= dd[pos].ff;
	}
}


/// get Divisors
vector<i64> get_div(i64 num)
{
	dd = get_p_div(num);
	res.clr;
	back_t(0,1);
	return res;
}

int f(i64 num,i64 base)
{
        int ans = 0;
        while(num)
        {
                if(num % base)
                       break;
                ans++;
                num /= base;
        }

        return ans;
}

int main()
{

	sieve();
	i64 n;
	while(cin >> n && n)
	{
		vector<i64> v = get_div(n);

                int ans = 0;
		For(i,v.sz)
                        ans += f(n,v[i]);

                cout << n << " " << ans << endl;
	}












	return 0;
}


