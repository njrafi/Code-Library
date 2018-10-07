

int fr[205],pre[205][205];
queue<int> v[205];

int main()
{

        int t,n,inp , cs = 1;
        sf(t);
        while(t--)
        {
                queue<int> v[205];
                mem(fr,0);
                mem(pre,0);
                sf(n);

                Fre(i,1,n+1)
                {
                        Fre(j,1,n+1)
                        {
                                sf(inp);
                                v[i].push(inp);
                                pre[i][inp] = j;
                        }
                }

                Fre(i,n+1,2*n+1)
                {
                        Fre(j,1,n+1)
                        {
                                sf(inp);
                                v[i].push(inp);
                                pre[i][inp] = j;
                        }
                }

                while(1)
                {
                        bool ok = 0;
                        Fre(i,1,n+1)
                                if(!fr[i] && !v[i].empty())
                                {
                                        ok = 1;
                                        int w = v[i].front();
                                        v[i].pop();
                                        if(!fr[w])
                                        {
                                                fr[w] = i;
                                                fr[i] = w;
                                        }
                                        else if(pre[w][i]<pre[w][fr[w]])
                                        {
                                                fr[fr[w]] = 0;
                                                fr[w] = i;
                                                fr[i] = w;
                                        }
                                }
                        if(!ok)
                                break;
                }
                CASE(cs++);
                Fre(i,1,n+1)
                        printf(" (%d %d)",i,fr[i]);
                puts("");
        }



        return 0;
}

