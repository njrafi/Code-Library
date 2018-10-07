
#define mxn 300005

mpi who;
int trie[mxn * 40][3];
int node;
int start[mxn];


void ins(int tree_node,int par_node,i64 num)
{
        int now = node++;
        start[tree_node] = now;
        int par_now = par_node;
        bool par_go = 1;

        for(int i = 33 ; i >= 0 ; i--)
        {
                bool nxt = checkbit(num,i);

                if(par_go)
                {
                        if(trie[par_now][1-nxt])
                                trie[now][1-nxt] = trie[par_now][1-nxt];

                        if(trie[par_now][nxt])
                                par_now = trie[par_now][nxt];
                        else
                                par_go = 0;
                }


                trie[now][nxt] = node++;

                now = trie[now][nxt];
        }
}


i64 min_cal(int now,i64 k)
{
        i64 ans = 0;
        for(int i = 33 ; i>= 0 ; i--)
        {
                bool nxt = checkbit(k,i);

                if(trie[now][nxt])
                        now = trie[now][nxt];
                else
                {
                        now = trie[now][nxt^1];
                        ans = setbit(ans,i);
                }
        }

        return ans;
}


i64 max_cal(int now,i64 k)
{
        i64 ans = 0;
        for(int i = 33 ; i>= 0 ; i--)
        {
                bool nxt = checkbit(k,i);
                nxt ^= 1;

                if(trie[now][nxt])
                {
                        ans = setbit(ans,i);
                        now = trie[now][nxt];
                }
                else
                        now = trie[now][nxt^1];
        }
        return ans;
}



pair<i64,i64> query(int nd,i64 k)
{

        return mp(min_cal(start[nd],k),max_cal(start[nd],k));
}

int main()
{
        i64 n,q,u,v,k,t,r;

        int now = 1;
        node = 1;



        cin >> n >> q >> r >> u;

        who[r] = now++;
        ins(who[r],0,u);


        For(i,n-1)
        {
                cin >> u >> v >> k;
                who[u] = now++;

                ins(who[u],start[who[v]],k);
        }

        i64 last_answer = 0;

        while(q--)
        {
            cin >> t;

            t ^= last_answer;

            if (!t)
            {
                cin >> v >> u >> k;

                u ^= last_answer;
                v ^= last_answer;
                k ^= last_answer;

                who[u] = now++;

                ins(who[u],start[who[v]],k);

            }
            else
            {
                cin >> v >> k;

                v ^= last_answer;
                k ^= last_answer;
                v = who[v];

                pii ans = query(v,k);

                i64 min_answer = ans.ff;
                i64 max_answer = ans.ss;

                cout << min_answer << " " << max_answer << endl;


                last_answer = min_answer ^ max_answer;
            }
        }
        return 0;
}


