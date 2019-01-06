
/// given a histogram gives max rectangular area in O(n)

i64 getMaxArea(vector<i64> hist)
{
        hist.pb(0);
        stack<i64> s;

        i64 mx = 0;
        i64 tp;         // top element
        i64 atp;        // area with top
        int i = 0;
        while (i < hist.sz)
        {
                if (s.empty() || hist[s.top()] <= hist[i])
                        s.push(i++);
                else
                {
                        tp = s.top();
                        s.pop();

                        if(s.empty())
                                atp = hist[tp] * i ;
                        else
                                atp = hist[tp] * (i - s.top() - 1);

                        mx = max(mx, atp);
                }
        }


        return mx;
}

int main()
{
        int t,cs = 1,n,inp;
        sf(t);
        while(t--)
        {
                sf(n);
                vector<i64> v;
                while(n--)
                {
                        sf(inp);
                        v.pb(inp);
                }

                CASE(cs++);
                cout << getMaxArea(v) << endl;
        }
        return 0;
}



