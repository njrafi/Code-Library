
vi v;
int cs;
i64 dp[64][3][64][3];
int vis[64][3][64][3];

void conv(i64 num)
{
        v.clr;
        if(!num)
                v.pb(0);

        while(num)
        {
                v.pb(num%2);
                num /= 2;
        }

        reverse(all(v));
}


i64 f(int pos,int eq,int ones,int prev)
{
        if(pos==v.sz)
                return ones;
        if(vis[pos][eq][ones][prev]==cs)
                return dp[pos][eq][ones][prev];
        vis[pos][eq][ones][prev] = cs;

        int hi = 2;
        if(eq)
                hi = v[pos] + 1;
        i64 ans = 0;
        For(i,hi)
                ans += f(pos+1 , eq && (i==v[pos]) , ones + (prev==i && i) , i);

        return dp[pos][eq][ones][prev] = ans;
}
int main()
{

        int t , csss  = 1;
        sf(t);
        i64 n;
        while(t--)
        {
                fastRead(&n);
                conv(n);
                cs++;
                CASE(csss++);
                fastWrite(f(0,1,0,0));

        }

        return 0;
}

