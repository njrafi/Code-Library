
#define mxn 10004

/// gives us a range rmq in o(n)
/// works if the range size is constant( m )


int ans[mxn];   /// ans[i] means [i-m+1,i] er ans
vi v;

int brute(int l,int r)
{
        int mn = inf;
        Fre(i,l,r+1)
                mn = min(mn , v[i]);
        return mn;
}

void f(int m)
{
        /// element , index
        deque<pii> dq;

        For(i,v.sz)
        {
                /// removing bigger elements from left side
                while(!dq.empty() && dq.front().ff>v[i])
                        dq.pop_front();

                dq.push_front(mp(v[i],i));


                /// removing out of range elements form right side
                while(!dq.empty() && dq.back().ss<=i-m)
                        dq.pop_back();

                if(i>=m-1)
                {

                        assert(dq.back().ff==brute(i-m+1,i));
                        ans[i] = dq.back().ff;
                }
        }
}


int main()
{
        srand(time(NULL));
        int n = 10004;
        int m = 234;

        For(i,n)
                v.pb(rand()%10 + 1);
        f(m);

        cout << "ok" << endl;

        return 0;
}


