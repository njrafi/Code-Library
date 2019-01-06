/*

Get the number with maximum product in a range

*/

vi vhi , vlo;
int dig[30][3][3][3];
bool eqlogg[30][3][3][3],eqhigg[30][3][3][3];
bool okgg[30][3][3][3];

i64 dp[30][3][3][3];

void conv(i64 lo,i64 hi)
{
        vlo.clr;
        vhi.clr;

        while(hi)
        {
                vhi.pb(hi%10);
                hi /= 10;
        }

        reverse(all(vhi));

        while(lo)
        {
                vlo.pb(lo%10);
                lo /= 10;
        }

        while(vlo.sz!=vhi.sz)
                vlo.pb(0);

        reverse(all(vlo));

}

i64 f(int pos,bool eqlo,bool eqhi,bool ok)
{
        if(pos==vhi.sz)
                return 1;
        if(dp[pos][eqlo][eqhi][ok]!=-1)
                return dp[pos][eqlo][eqhi][ok];

        int lo = 0 , hi = 9;

        if(eqlo)
                lo = vlo[pos];
        if(eqhi)
                hi = vhi[pos];

        i64 ans = 0;
        Fre(i,lo,hi+1)
        {

                i64 gun = i;
                if(!gun && !ok)
                        gun = 1;

                i64 tem = gun * f(pos+1, eqlo && (i==vlo[pos]) , eqhi && (i==vhi[pos]), ok || i);

                if(tem>=ans)
                {
                        ans = tem;
                        dig[pos][eqlo][eqhi][ok] = i;
                        eqlogg[pos][eqlo][eqhi][ok] = eqlo && (i==vlo[pos]);
                        eqhigg[pos][eqlo][eqhi][ok] = eqhi && (i==vhi[pos]);
                        okgg[pos][eqlo][eqhi][ok] = ok || i;
                }
        }
        return dp[pos][eqlo][eqhi][ok] = ans;
}


i64 last;

void get_num(int pos,bool eqlo,bool eqhi,bool ok)
{
        if(pos==vhi.sz)
                return;

        last *= 10;
        last += dig[pos][eqlo][eqhi][ok];

        get_num(pos+1,eqlogg[pos][eqlo][eqhi][ok],eqhigg[pos][eqlo][eqhi][ok],okgg[pos][eqlo][eqhi][ok]);
}

int main()
{

        i64 lo,hi;
        while(cin >> lo >> hi)
        {

                conv(lo,hi);
                mem(dp,-1);
                f(0,1,1,0);
                last = 0;
                get_num(0,1,1,0);

                cout << last << endl;
        }

        return 0;
}


