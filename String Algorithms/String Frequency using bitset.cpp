/// Gives occurance of pattern in text that no occurances
/// intersect each other

#define mxn 100005


bitset<mxn> f[26] , p;
char s[mxn];
map<string , int> dp;
int main()
{

        int t,cs = 1,n;
        t = 1;

        while(t--)
        {
                For(i,26)
                        f[i].reset();
                dp.clr;
                sf(n);
                sf(n);
                scanf("%s",s);
                int ssz1 = strlen(s);
                For(i,ssz1)
                        f[s[i]-'a'][i] = 1;
                while(n--)
                {
                        scanf("%s",s);

                        string ss = s;

                        if(dp.find(ss)!=dp.end())
                        {
                                pfn(dp[ss]);
                                continue;
                        }
                        int ssz = strlen(s);

                        p.set();
                        For(i,ssz)
                                p &= (f[s[i]-'a']>>i) ;


                        int ans = 0;
                        for(int i = p._Find_first() ; i < ssz1 ; i = p._Find_next(i + ssz - 1))
                              ans++;

                        dp[ss] = ans;

                        pfn(ans);

                }
        }

        return 0;
}


