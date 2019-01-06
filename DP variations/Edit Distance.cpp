
int dp[2005][2005];
char s1[3000],s2[3000];

int edit(int n,int m)
{
        if(n==-1)                       // add all m letters to s1
                return m+1;
        if(m==-1)
                return n+1;             // remove all n letters from s1
        if(dp[m][n]!=-1)
                return dp[m][n];
        if(s1[n]==s2[m])
                return dp[n][m] = edit(n-1,m-1);
        else
                return dp[n][m] = min3( edit(n,m-1) , edit(n-1,m-1),edit(n-1,m)) + 1;
                                //       insert    ,   replace,     remove      in s1
}
int main()
{

        //ios_base::sync_with_stdio(false);cin.tie(0);
        int t;
        sf(t);
        while(t--)
        {
                scanf("%s %s",s1,s2);
                mem(dp,-1);

                printf("%d\n", edit(strlen(s1)-1,strlen(s2)-1) );
        }

        return 0;
}

