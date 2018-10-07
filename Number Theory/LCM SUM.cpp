

/*

n/2 * ( ∑ d | n ( phi(d)×d) + 1 )
gives us the sum of lcm(i,n)  where 1<= i <= n

from that we can can calculate all pair lcm sum :D
all pair means lcm(i,j) where 1<=i<=n and  i+1 <= j <=n

*/


#define mxn 3000006
i64 res[mxn];
i64 phi[mxn];
bool ispr[mxn];

void sieve()
{
	int gg = 0;

        for(int i = 1 ; i < mxn ; i++)
                for(int j = i ; j < mxn ; j += i)
                        res[j] += phi[i] * i;

        res[0] = 0;
        Fre(i,1,mxn)
        {
                res[i]++;
                res[i] /= 2;
                res[i] *= (i64)i;


                /// comment it out if you dont want all pair just sum of lcm(i,n)
                res[i] += res[i-1] - i;
        }

}


void sievephi()
{
        For(i,mxn)
                phi[i] = (i64)i;

        Fre(i,2,mxn)
                if(!ispr[i])
                        for(int j=i;j<mxn;j+=i)
                        {
                                ispr[j] = 1;
                                phi[j] = (phi[j]/i)*(i-1);
                        }
}



int main()
{

	sievephi();
	sieve();
//        assert(1==2);
	int t,n,cs = 1;

	sf(t);
	while(t--)
	{
		fastRead(&n);
                CASE(cs++);
                fastWrite(res[n]);
	}

	return 0;
}



