/*
Remove the max 2 elements merge them
and push them back to the priority queue
until there is one element
*/

int main()
{

        int t,n;
        sf(t);
        while(t--)
        {
                priority_queue<i64,vector<i64>,greater<i64> > p;
                sf(n);
                Fre(i,1,n+1)
                        p.push(i);
                i64 ans = 0;
                while(p.sz>1)
                {
                        i64 tem = p.top();
                        p.pop();
                        tem += p.top();
                        p.pop();
                        ans += tem;

                        p.push(tem);
                }

                cout << ans << endl;
        }

        return 0;
}

