
#define mxn 100

int row[mxn];
int col[mxn];
int dp[mxn][mxn];


int f(int st,int en)
{
        if(st>=en)
                return 0;
        if(dp[st][en]!=-1)
                return dp[st][en];

        int ans = inf;

        Fre(i,st,en)
        {
                int l = f(st,i);
                int r = f(i+1,en);
                int tem = l + r + row[st] * col[i] * col[en];
                ans = min(ans,tem);
        }

        return dp[st][en] = ans;
}


int main()
{


        int n;
        sf(n);
        For(i,n)
                sff(row[i],col[i]);

        mem(dp,-1);
        cout << f(0,n-1) << endl;

        return 0;
}

