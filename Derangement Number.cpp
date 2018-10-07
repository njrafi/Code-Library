
/*
A derangement is a permutation with no fixed points.
That is, a derangement of a set leaves no element in its original place.
For example, the derangements of {1,2,3} are {2,3,1} and {3,1,2},
but {3,1,2} is not a derangement of  because 2 is a fixed point.

D(n) = (n-1) * D(n-2) + (n-1) * D(n-1) where D(0) = 1 , D(1) = 0

if(n>22) it will overflow

*/


i64 dp[40];

i64 f(int n)
{
        if(n<2)
                return 1-n;
        if(dp[n])
                return dp[n];

        return dp[n] = (n-1) * (f(n-1) + f(n-2)) ;

}


int main()
{

        int n;
        while(cin >> n)
                cout << f(n) << endl;
        return 0;
}


