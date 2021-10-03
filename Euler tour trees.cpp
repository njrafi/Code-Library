/*
Euler tour tree which supports
1. lca of 2 node
2. path sum of 2 node ( value is in node)
3. update node value

https://codeforces.com/blog/entry/18369
https://www.youtube.com/watch?v=MOy4UDjN8DM&t=92s
the problem: https://codeforces.com/contest/1575/problem/I

*/

#define mxn 3 * 100005

struct SegmentTreeNode {
    i64 valueSum;
    int height;
    int node;
    SegmentTreeNode() {
        valueSum = 0;
        height = inf;
    }

    SegmentTreeNode(i64 valueSum, int height,int node) {
        this->valueSum = valueSum;
        this->height = height;
        this->node = node;
    }
};

SegmentTreeNode merge(SegmentTreeNode a, SegmentTreeNode b) {
    a.valueSum += b.valueSum;
    if(a.height >= b.height) a.node = b.node;
    a.height = min(a.height,b.height);
    return a;
}

SegmentTreeNode tree[4 * mxn];

void update(int n,int st,int en,int idx,SegmentTreeNode val) {
    if(st==en) {
        if(val.height == -1) val.height = tree[n].height;
        tree[n] = val;
        return ;
    }

    int mid = (st+en)/2, lc = 2 * n, rc = lc  + 1;

    if(idx<=mid)
        update(lc,st,mid,idx,val);
    else
        update(rc,mid+1,en,idx,val);

    tree[n] = merge(tree[lc], tree[rc]);
}


SegmentTreeNode query(int n,int st,int en,int l,int r) {
    if(r < st || en < l)
        return SegmentTreeNode();
    if(l <= st && en <= r)
        return tree[n];

    int mid = (st+en)/2, lc = 2 * n, rc = lc  + 1;

    auto q1 = query(lc,st,mid,l,r);
    auto q2 = query(rc,mid+1,en,l,r);

    return merge(q1,q2);
}

int dfsTime;
int starTime[mxn];
int endTime[mxn];
int value[mxn];
vi v[mxn];

/*
startTime of a node = the first time it is visited
endTime of a node = the time when we leave the node
we add a positive value in startTime and negative in endTime
We also add a zero value after every child time visit which helps us get lca
*/

void dfs(int node,int height = 0,int par = 1) {
    starTime[node] = dfsTime++;
    update(1,1,mxn,starTime[node],{value[node],height,node});

    for(auto child: v[node]) {
        if(child == par) continue;
        dfs(child,height+1,node);
        update(1,1,mxn,dfsTime,{0,height,node});
        dfsTime++;
    }

    endTime[node] = dfsTime++;
    update(1,1,mxn,endTime[node],{-value[node],height,node});
}

void init() {
    dfsTime = 1;
}

int getLCA(int a,int b) {
    if(starTime[a] > starTime[b]) swap(a,b);
    SegmentTreeNode q = query(1,1,mxn,starTime[a],starTime[b]);
    return q.node;
}

void update(int node,int newValue) {
    value[node] = newValue;
    update(1,1,mxn,starTime[node],{value[node],-1,node});
    update(1,1,mxn,endTime[node],{-value[node],-1,node});
}

i64 getPathSum(int a,int b) {
    int lca = getLCA(a,b);
    i64 aSum = query(1,1,mxn,starTime[lca],starTime[a]).valueSum;
    i64 bSum = query(1,1,mxn,starTime[lca],starTime[b]).valueSum;
    return aSum + bSum - value[lca];

}


int main() {

    init();
    int a,b,n,q;
    sff(n,q);

    Fre(i,1,n+1) {
        sf(value[i]);
        value[i] = abs(value[i]);
    }

    For(i,n-1) {
        sff(a,b);
        v[a].pb(b);
        v[b].pb(a);
    }

    dfs(1);

    int op;
    while(q--) {
        sfff(op,a,b);
        if(op == 2)
            printf("%lld\n", 2 * getPathSum(a,b) - value[a] - value[b]);
        else
            update(a,abs(b));
    }

        return 0;
}

