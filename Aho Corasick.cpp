
#define mxn 500 * 500 + 5
/// should be equal to total dictionary size sum

int node;

int trie[mxn][30];
int vis[mxn];
/// number of times a trie node is visited
int f[mxn];
/// failure function


int ins(string s)
{
        int u = 0;
        For(i,s.sz)
        {
                int c = s[i]-'a';
                if(!trie[u][c])
                    trie[u][c] = node++;
                u = trie[u][c];

        }

        /// returns end node
        return u;
}

void clear_stuff()
{
        node = 1;
        mem(trie,0);
        mem(vis,0);
        mem(f,0);
}

void build_fail()
{
        queue<int> q;
        int i;
        For(i,26)
        {
                if(trie[0][i])
                        q.push(trie[0][i]);
        }

        int r,u,v;
        while(!q.empty())
        {
                r = q.front();
                q.pop();
                For(c,26)
                {
                        u = trie[r][c];
                        if(!u)
                                continue;
                        q.push(u);
                        v = f[r];
                        while(v && trie[v][c]==0)
                                v = f[v];
                        f[u] = trie[v][c];
                }
        }
}


void search_trie(string s)
{
        int j = 0;
        For(i,s.sz)
        {
                int c = s[i]-'a';
                while(j && trie[j][c]==0)
                    j = f[j];
                j = trie[j][c];
                int tem = j;
                while(tem)
                {
                        vis[tem]++;
                        tem = f[tem];
                }
        }
}

char sss[1000006];

int main()
{

        int t,n,cs = 1;
        sf(t);
        while(t--)
        {
                clear_stuff();
                vi v;
                sf(n);
                string text , s;
                scanf("%s",sss);
                text = sss;
                while(n--)
                {
                        scanf("%s",sss);
                        s = sss;
                        v.pb(ins(s));
                }

                build_fail();

                search_trie(text);

                CASE(cs++);
                For(i,v.sz)
                        pfn(vis[v[i]]);
        }

        return 0;
}
