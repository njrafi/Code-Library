
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
                v.pb(num%10);
                num /= 10;
        }

        reverse(all(v));
}


i64 f(int pos,int eq,int ones,int ok)
{
        if(pos==v.sz)
                return ones;
        if(vis[pos][eq][ones][ok]==cs)
                return dp[pos][eq][ones][ok];

        vis[pos][eq][ones][ok] = cs;

        int hi = 10;
        if(eq)
                hi = v[pos] + 1;

        i64 ans = 0;
        For(i,hi)
        {
                int nones = ones;
                if(!i && ok)
                        nones++;

                ans += f(pos+1 , eq && (i==v[pos]) , nones , ok || i);
        }

        return dp[pos][eq][ones][ok] = ans;
}
int main()
{

        int t , csss  = 1;
        sf(t);
        i64 n;
        while(t--)
        {
                fastRead(&n);
                n--;
                i64 ans1 = -1;
                if(n>=0)
                {
                        conv(n);
                        cs++;
                        ans1 = f(0,1,0,0);
                }

                fastRead(&n);
                conv(n);
                cs++;
                i64 ans2 = f(0,1,0,0);
//                cout << ans2 << " " << ans1 << endl;

                CASE(csss++);
                fastWrite(ans2 - ans1) ;
        }

        return 0;
}

