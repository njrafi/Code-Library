

// idea : think of the multiplication table
// Can also be used for number of divisors
/// 10^7 run in 1 sec

#define mxn 2000007

int nod[mxn];
int sod[mxn];

void sieve()
{
        for(int i =1 ; i*i < mxn ; i++)
                for(int j=i ; i*j <mxn ; j ++)
                {
                        sod[i*j] += i + j;
                        nod[i*j] += 2;
                        if(i==j)
                        {
                                sod[i*j] -= j;
                                nod[i*j]--;
                        }
                }
}
int main()
{

        int start_s=clock();
        sieve();
        int stop_s=clock();
        cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
        int n;
        while(1)
        {
                sf(n);
                if(!n)
                        break;

                printf("%d %d\n",nod[n],sod[n]);
        }
        return 0;
}

