
i64 ans;
vi v[100005];
map< i64 ,i64> gg;

i64 dfs(int s)
{

        i64 sum = 33 ;

        For(i,v[s].sz)
        {
                i64 tem = dfs(v[s][i]);
                gg[tem]++;
                sum += tem * 33 ;
        }

        return sum ;
}

int main()
{


        int n , a , b;
        sf(n);
        For(i,n-1)
        {
                sff(a,b);
                v[a].pb(b);
        }
        dfs(1);
        foreach(i,gg)
        {
                i64 tem = i->ss;
                ans += (tem * (tem-1)) / 2;
        }
        cout << ans << endl;








        return 0;
}

