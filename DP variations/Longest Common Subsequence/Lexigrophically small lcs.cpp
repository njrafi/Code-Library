
string s1,s2;
string dp[105][105];
int cs,vis[105][105];

string f(int l,int r)
{
        if(l==s1.sz || r==s2.sz)
                return "";

        if(vis[l][r]==cs)
                return dp[l][r];
        vis[l][r] = cs;
        string ans;
        if(s1[l]==s2[r])
                ans = s1[l] + f(l+1,r+1);
        else
        {

                string r1 = f(l+1,r);
                string r2 = f(l,r+1);
                if(r1.sz>r2.sz)
                        ans = f(l+1,r);
                else if(r1.sz==r2.sz && r1<=r2)
                        ans = f(l+1,r);
                else
                        ans = f(l,r+1);

        }

        return dp[l][r] = ans;
}



int main()
{

        int t;
        sf(t);

        while(t--)
        {
                cin >> s1 >> s2;

                CASE(++cs);
                string ans = f(0,0);

                if(!ans.sz)
                        puts(":(");
                else
                        cout << ans << endl;
        }
        return 0;
}
