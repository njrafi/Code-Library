/// Normal LCS

string s1,s2;
int cs;
int dp[1005][1005];
int vis[1005][1005];


int f(int l,int r)
{
        if(l==s1.sz || r==s2.sz)
                return 0;
        if(vis[l][r]==cs)
                return dp[l][r];
        vis[l][r] = cs;

        int ans = 0;
        if(s1[l]==s2[r])
                ans = 1 + f(l+1,r+1);
        
        ans = max(f(l+1,r),f(l,r+1));
        return dp[l][r] = ans;
}

int main()
{
        
        while(getline(cin,s1))
        {
                getline(cin,s2);
                cs++;

                cout << f(0,0) << endl;
        }
        return 0;
}

