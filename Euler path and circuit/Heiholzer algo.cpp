

// Print the Eular path or circuit

#define mxn 1002

vi v[mxn];
int ok[mxn][mxn];
vi path,tem;

void euler_path(int now)
{
        while(1)
        {
                bool nb = 0;
                For(i,v[now].sz)
                {
                        int w = v[now][i];
                        if(ok[now][w])
                        {
                                nb = 1;
                                tem.pb(now);
                                ok[now][w] = 0;
                                ok[w][now] = 0;
                                now = w;
                                break;
                        }
                }
                if(!nb)
                {
                        path.pb(now);
                        if(tem.empty())
                                break;
                        now = tem.back();
                        tem.pop_back();
                }
        }

        reverse(all(path));
        For(i,path.sz)
                cout << path[i] << " ";
        cout << endl;
}

int main()
{
        int n,m,a,b;
        sff(n,m);

        while(m--)
        {
                sff(a,b);
                v[a].pb(b);
                v[b].pb(a);
                ok[a][b] = 1;
                ok[b][a] = 1;
        }

        euler_path(1);

        return 0;
}

