
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including treegg_order_statistics_node_update
using namespace __gnu_pbds;

typedef tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define mxn 10005

ordered_set treegg[4*mxn];

int hudai;

/// adds a element val in index idx
/// O( (logn)^2 )
void add(int n,int st,int en,int idx,int val)
{
        if(st==en)
        {
                treegg[n].insert( {val,hudai++});
                return;
        }

        int mid = (st+en)/2 , lc = 2 * n , rc = lc + 1;
        if(idx <= mid)
                add(lc,st,mid,idx,val);
        else
                add(rc,mid+1,en,idx,val);
        treegg[n].insert( {val, hudai++} );
        return;
}

// remove a value val from index idx
/// O( (logn)^2 )
void rem(int n,int st,int en,int idx,int val)
{
        if(st==en)
        {
                treegg[n].erase( treegg[n].lower_bound({val,-inf}) );
                return;
        }

        int mid = (st+en)/2 , lc = 2 * n , rc = lc + 1;
        if(idx <= mid)
                add(lc,st,mid,idx,val);
        else
                add(rc,mid+1,en,idx,val);
        treegg[n].erase( treegg[n].lower_bound({val,-inf}) );
        return;
}

// returns number elements between having value of [i,j] in the range [l,r]
/// O( (logn)^2 )
int query(int n,int st,int en,int l,int r,int i,int j)
{
        if(en<l || st>r)
                return 0;
        if(l<=st && en<=r)
                return treegg[n].order_of_key({j,inf}) - treegg[n].order_of_key({i,-inf});
        int mid = (st+en)/2 , lc = 2 * n , rc = lc + 1;
        return query(lc,st,mid,l,r,i) + query(rc,mid+1,en,l,r,i);

}


