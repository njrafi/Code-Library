
/// given n numbers print first k smallest subset sum


vi v;
#define pgg pair<i64,int>

int main()
{

        int n,k,inp;
        i64 negsum = 0;

        sff(n,k);

        For(i,n)
        {
                sf(inp);

                // for negative number we make it positive
                if(inp<0)
                {
                        negsum += inp;
                        inp = -inp;
                }
                v.pb(inp);

        }

        sort(all(v));
        priority_queue<pgg,vector<pgg>,greater<pgg> > p;

        p.push(mp(v[0],0));


        // comment it out if no negative or if zero element is not allowed
        cout << negsum << endl;

        k--;

        while(k--)
        {
                i64 num = p.top().ff;
                int idx = p.top().ss;
                cout << negsum + num << endl;
                p.pop();

                if(idx+1<v.sz)
                {
                        p.push(mp(num+v[idx+1],idx+1));
                        p.push(mp(num-v[idx] + v[idx+1] , idx + 1));
                }
        }

        return 0;
}


