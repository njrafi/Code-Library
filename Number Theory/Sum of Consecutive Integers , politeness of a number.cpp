
/*


Politeness
the number of ways a number can be expressed as (2 or more)consecutive integer sum
The ans is the odd divisors of the number greater than 1

*/


int politeness(i64 num)
{
	vector<i64> v = get_divisors(num);

        int ans = 0;
	For(i,v.sz)
	{
                if(v[i]%2)
                        ans++;
	}
	return ans-1;
}


int main()
{

	sieve();
	int t,cs =1;
	i64 n;
	sf(t);
	while(t--)
        {
                cin >> n;
                CASE(cs++);
		cout << politeness(n) << endl;
        }


	return 0;
}


