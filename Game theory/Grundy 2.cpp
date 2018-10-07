
#define mxn 20004

vi v[mxn];
int grundy[mxn];
int ball[mxn];

int dfs(int u)
{
        si s;

        For(i,v[u].sz)
        {
                int vv = v[u][i];
                s.insert(dfs(vv));
        }

        int now = 0;

        foreach(i,s)
                if(*i!=now)
                        break;
                else
                        now++;
        return grundy[u] = now;
}
int main()
{

        int t,cs = 1,n,inp;
        sf(t);
        while(t--)
        {
                mem(v,NULL);

                sf(n);
                Fre(i,1,n+1)
                        sf(ball[i]);

                Fre(i,1,n+1)
                {
                        sf(inp);
                        if(inp)
                                v[inp].pb(i);
                }
                dfs(1);


                int ans = 0;

                Fre(i,1,n+1)
                        if(ball[i]%2)
                                ans ^= grundy[i];


                CASE(cs++);
                if(ans)
                        puts("first");
                else
                        puts("second");

        }
        return 0;
}

