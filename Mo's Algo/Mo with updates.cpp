
#define mxn 100005


// https://vjudge.net/contest/216753#problem/G

struct queries
{
        int l,r,t,id;
        // left,right,time,index
        queries(){}
        queries(int ll,int rr,int tt,int idx)
        {
                l = ll;
                r = rr;
                t = tt;
                id = idx;
        }
};

struct updates
{
        int id,pre,now;
        // index,prev value,new value

        updates(){}
        updates(int idx,int xpre,int xnow)
        {
                id = idx;
                pre = xpre;
                now = xnow;
        }
};



int arr[mxn];   // original array
int last[mxn];  // last state before update
vector<queries> Q;      // to store queries
vector<updates> U;      // to store updates
i64 ans[mxn];           // last ans;
int L,R,T,cnt[1000006];     // pointers and count
// remember cnt array size is not mxn ;)

int sum;                // current ans
int blockSize;          //

bool cmp(queries a,queries b)
{
        int l1 = a.l/blockSize;
        int l2 = b.l/blockSize;
        int r1 = a.r/blockSize;
        int r2 = b.r/blockSize;
        if(l1 != l2) return l1 < l2;
        if(r1 != r2) return r1 < r2;

        return a.t<b.t;
}


void add(int id)
{
        cnt[arr[id]]++;
        if(cnt[arr[id]] == 1)
                sum++;
}


void rem(int id)
{
        cnt[arr[id]]--;
        if(cnt[arr[id]] == 0)
                sum--;
}

void apply(int id,int val)
{
        if(L<=id && id<=R) rem(id);
        arr[id] = val;
        if(L<=id && id<=R) add(id);
}

int get_ans()
{
        return sum;
}


void mo_with_update()
{
        sort(all(Q),cmp);
        mem(cnt,0);

        L = 0 , R = - 1 , sum = 0, T = 0;

        For(i,Q.sz)
        {
                while(T < Q[i].t)
                {
                        T++;
                        apply(U[T].id,U[T].now);
                }

                while(T > Q[i].t)
                {
                        apply(U[T].id , U[T].pre);
                        T--;
                }

                while(L > Q[i].l) add(--L);

                while(R < Q[i].r) add(++R);

                while(L < Q[i].l) rem(L++);

                while(R > Q[i].r) rem(R--);

                ans[Q[i].id] = get_ans();
        }
}



void process_input(int q)
{

        Q.clr;
        U.clr;
        U.pb( updates(0,0,0) );

        int l,r;
        char op[3];

        For(i,q)
        {
                scanf("%s",op);
                if(op[0]=='Q')
                {
                        sff(l,r);
                        r--;
                        Q.pb( queries(l,r,(int)U.sz - 1,(int)Q.sz) );
                }
                else
                {
                        sff(l,r);
                        U.pb( updates(l,last[l],r));
                        last[l] = r;
                }
        }
        mo_with_update();
}


int main()
{


        int n,q;
        sff(n,q);


        blockSize = 2160;

        For(i,n)
        {
                sf(arr[i]);
                last[i] = arr[i];
        }

        process_input(q);


        For(i,Q.sz)
                pfn(ans[i]);


        return 0;
}



