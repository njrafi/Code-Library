

#define mxn 100005
#define siv 1000006
vi pr;
bool isp[siv];
vi fact[mxn];


void sieve()
{
        int lim = sqrt(siv) + 2;
        Fre(i,2,lim)
                if(!isp[i])
                        for(int j = 2*i ; j < siv ; j += i)
                                isp[j] = 1;
        Fre(i,2,siv)
                if(!isp[i])
                        pr.pb(i);

}

void factorize(int n,int id)
{
        for(int i = 0 ; i<pr.sz && pr[i] < sqrt(n)+2 ; i++)
                while(n%pr[i]==0)
                {
                        fact[id].pb(pr[i]);
                        n /= pr[i];
                }
        if(n>1)
                fact[id].pb(n);

}




vi tree[4*mxn];
void build(int n,int l,int r)
{
        if(l==r)
        {
                For(i,fact[l].sz)
                        tree[n].pb(fact[l][i]);
                return;
        }
        int mid = (l+r)/2 , lc = 2 * n , rc = lc + 1;
        build(lc,l,mid);
        build(rc,mid+1,r);
        // sort and merge 2 vectors into new one
        merge(all(tree[lc]),all(tree[rc]),back_inserter(tree[n]));              
}


int query(int n,int st,int en,int l,int r,int i,int j)
{
        if(en<l || st>r)
                return 0;
        if(l<=st && en<=r)
                return upper_bound(all(tree[n]),j) - lower_bound(all(tree[n]),i);
        int mid = (st+en)/2 , lc = 2 * n , rc = lc + 1;

        return query(lc,st,mid,l,r,i,j) + query(rc,mid+1,en,l,r,i,j);

}

int main()
{

        sieve();
        int n,q,inp,l,r,a,b;
        sf(n);
        For(i,n)
        {
                sf(inp);
                if(!isp[inp])
                        fact[i].pb(inp);
                else
                        factorize(inp,i);
        }
        build(1,0,n-1);
        sf(q);
        while(q--)
        {
                sff(l,r);
                sff(a,b);
                pfn(query(1,0,n-1,l-1,r-1,a,b));
        }
        return 0;
}

