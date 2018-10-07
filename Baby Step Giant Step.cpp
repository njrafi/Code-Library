
/// given a^x % mod = res ,  finds the x in O(sqrt(mod))
/// mod must be prime

i64 baby_giant(i64 a,i64 res,i64 m)
{


        i64 k = sqrt(m) + 2;
        map<i64,i64> val;
        vector<i64> ret;

        i64 now = 1;

        For(i,k)
        {

                if(val.find(now)==val.end())
                        val[now] = i;
                now = (now * a) % m;
        }


        /// down = a ^ (-k)
        i64 down = modinverse(now,m);
        now = res;

        For(j,k)
        {

                if(val.find(now)!=val.end())
                        ret.pb(val[now] + j * k);

                now *= down;
                now %= m;

        }


        if(ret.empty())
                return -1;

        sort(all(ret));

        return ret[0];
}

int main()
{

        int t,cs = 1,a,res;
        sf(t);
        while(t--)
        {
                sff(a,res);
                CASE(cs++);
                pfn(baby_giant(a,res,100000007));
        }

        return 0;
}


