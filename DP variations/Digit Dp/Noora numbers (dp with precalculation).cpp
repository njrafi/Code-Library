

/// the idea is to only store for eq = 0
/// and calculate the other states


vi v;
i64 dp[22][1030][3];

i64 f(int pos,int mask,bool ok,bool eq)
{

        if(pos==v.sz)
        {
                int dis = 0;
                int mx = 0;
                For(i,10)
                        if(checkbit(mask,i))
                        {
                                mx = i;
                                dis++;
                        }
                if(dis==mx && ok)
                        return 1;

                return 0;
        }
        if(!eq && dp[pos][mask][ok]!=-1)
                return dp[pos][mask][ok];

        int hi = 10;
        if(eq)
                hi = v[pos]+1;

        i64 ans = 0;
        For(i,hi)
        {
                int nok = ok | i;
                int nmask = mask;
                if(nok)
                        nmask = setbit(mask,i);
                ans += f(pos+1,nmask,ok | i, eq && (i==v[pos]));
        }

        if(!eq)
                dp[pos][mask][ok] = ans;

        return ans;
}


void conv(i64 n)
{
        v.clr;
        while(n)
        {
                v.pb(n%10);
                n /= 10;
        }


        while(v.sz!=20)
                v.pb(0);

        reverse(all(v));


//        For(i,v.sz)
//                cout << v[i] << " ";
//        cout << endl;



}


int main()
{

        int t,cs = 1;
        i64 n;
        mem(dp,-1);
        sf(t);
        while(t--)
        {

                gg = 0;
                scanf("%lld",&n);
                conv(n);
                printf("%lld\n", f(0,0,0,1));
        }

        return 0;
}


