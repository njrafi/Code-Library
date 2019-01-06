/*
We have n non_negative integers. 
We need max (non-empty) consecutive subarray sum modulo p
ans also thenumber of segments with this maximum score.
*/


vector<i64> v;

int main()
{

        i64 t,n,inp,m;
        fastRead(&t);

        while(t--)
        {
                fastRead(&n);
                fastRead(&m);

                v.clr;

                For(i,n)
                {
                        fastRead(&inp);
                        v.pb(inp);
                }

                i64 pre = 0,ans = -1;
                i64 freq = 0;
                unordered_map<i64,i64> scount;
                set<i64> s;

                For(i,n)
                {

                        pre = (pre + v[i]) % m;
                        if(pre==ans)
                                freq++;
                        else if(pre>ans)
                        {
                                ans = pre;
                                freq = 1;
                        }
                        i64 gg = 0;
                        set<i64>::iterator iss= s.lower_bound(pre+1);
                        if(iss!=s.end())
                                gg = *iss;
                        i64 tem = ((i64)pre-(i64)gg+(i64)m)% (i64)m;

                        if(tem>ans)
                        {
                                freq = scount[gg];
                                ans = tem;
                        }
                        else if(tem==ans)
                        {
                                freq += scount[gg];
                        }
                        s.insert(pre);
                        scount[pre]++;
                }

                fastWrites(ans);
                fastWrite(freq); ;

        }
        return 0;
}


