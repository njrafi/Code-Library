/// This is n logn too :p

int lissize(vi a)
{
        vi v;

        For(i,a.sz)
        {
                /// For longest non-decreasing use upper_bound

                vi::iterator it = lower_bound(all(v),a[i]);

                if(it==v.end())
                        v.pb(a[i]);
                else
                        v[it-v.begin()] = a[i];
        }

        return v.sz;
}

int main()
{

        int n,inp;
        vi v;
        sf(n);
        while(n--)
        {
                sf(inp);
                v.pb(inp);

        }
        cout << lissize(v) << endl;

        return 0;
}


