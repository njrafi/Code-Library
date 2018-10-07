
vi v;

void div(i64 n)
{
        v.clr;
        int tem = sqrt(n);
        Fre(i,1,tem+1)
                if(n%i==0)
                {
                        v.pb(i);
                        if(n/i!=i)
                                v.pb(n/i);
                }
        sort(all(v));
}
int main()
{
        i64 n;
        while(cin >> n)
        {
                div(n);
                For(i,v.sz)
                        cout << v[i] << " ";
                cout << endl;
        }
        return 0;
}

