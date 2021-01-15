// https://www.spoj.com/problems/MKTHNUM/

#define mxn 100005


vi tree[4 * mxn];
vpi v;  // number, index

void build(int n,int l,int r) {
        if(l==r) {
                tree[n].pb(v[l].ss);
                return;
        }

        int mid = (l+r)/2 , lc = 2 * n , rc = lc + 1;
        build(lc,l,mid);
        build(rc,mid+1,r);
        // sort and merge 2 vectors into new one
        merge(all(tree[lc]),all(tree[rc]),back_inserter(tree[n]));
}

// kth number in [l,r], k is 1-based
int getkTh(int n,int st,int en,int l,int r,int k) {
        if(st == en) return v[st].ff;

        int mid = (st + en) / 2, lc = 2 * n, rc = lc + 1;

        int leftChildNumbersInRange = upper_bound(all(tree[lc]),r) - lower_bound(all(tree[lc]),l);

        if(leftChildNumbersInRange >= k)
                return getkTh(lc,st,mid,l,r,k);
        return getkTh(rc,mid+1,en,l,r,k - leftChildNumbersInRange);
}

int main() {

        int n,q,inp,l,r,k;
        sff(n,q);

        Fre(i,1,n+1) {
                sf(inp);
                v.pb({inp,i});
        }

        sort(all(v));


        build(1,0,n-1);

        while(q--) {
                sfff(l,r,k);
                pfn(getkTh(1,0,n-1,l,r,k));
        }




        return 0;
}




