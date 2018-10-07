///change if needed
#define mxn 100005

struct queryInfo
{
        int l,r,idx;

        queryInfo(){}
        queryInfo(int ll,int rr,int ii)
        {
                l = ll;
                r = rr;
                idx = ii;
        }
};


bool cmp(queryInfo a,queryInfo b)
{
        if(a.l/block==b.l/block)
                return a.r<b.r;
        return a.l<b.l;
}



int block = sqrt(mxn);

vector<queryInfo> queries;

int val[mxn];   // array value
int ans[mxn];   // last ans


/// change accordigly to problem
int mx;         // max result for now
int lvl[mxn];   // ei level e koyjon ache
int cnt[mxn];


void add(int idx)
{
        int gg = val[idx];
        lvl[cnt[gg]]--;

        cnt[gg]++;
        lvl[cnt[gg]]++;

        mx = max(mx,cnt[gg]);

}

void rem(int idx)
{
        int gg = val[idx];
        lvl[cnt[gg]]--;


        if(cnt[gg]==mx && !lvl[cnt[gg]])
                mx = cnt[gg] - 1;

        cnt[gg]--;
        lvl[cnt[gg]]++;
}


void doThings()
{

        int pl = queries[0].l , pr = queries[0].l - 1 ;

        /// memset Things or initialize
        mem(cnt,0);
        mem(lvl,0);
        mx = 0;


        For(i,queries.sz)
        {
                int l = queries[i].l;
                int r = queries[i].r;


                while(pr < r)
                {
                        pr++;
                        add(pr);
                }

                while(pr > r)
                {
                        rem(pr);
                        pr--;
                }


                while(pl<l)
                {
                        rem(pl);
                        pl++;
                }

                while(pl>l)
                {
                        pl--;
                        add(pl);
                }



                ans[queries[i].idx] = mx;


        }
}


int main()
{
        int t,cs = 1,n,c,q,l,r;
        sf(t);

        while(t--)
        {

                queries.clr;
                sfff(n,c,q);

                block = sqrt(n);

                Fre(i,1,n+1)
                        sf(val[i]);


                For(i,q)
                {
                        sff(l,r);
                        queries.pb(queryInfo(l,r,i));
                }

                sort(all(queries),cmp);

                doThings();

                CASE(cs++);
                For(i,q)
                        pfn(ans[i]);
        }

        return 0;
}


