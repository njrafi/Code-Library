
#define mxn 30005

int tree[4 * mxn];


void update(int n,int st,int en,int idx,int val)
{
        if(st==en)
        {
                tree[n] = val;
                return ;
        }

        int mid = (st+en)/2 , lc = 2 * n , rc = lc  + 1;

        if(idx<=mid)
                update(lc,st,mid,idx,val);
        else
                update(rc,mid+1,en,idx,val);

        tree[n] = tree[lc] + tree[rc];
}


int query(int n,int st,int en,int l,int r)
{
        if(r < st || en < l)
                return 0;
        if(l <= st && en <= r)
                return tree[n];

        int mid = (st+en)/2 , lc = 2 * n , rc = lc  + 1;

        int q1 = query(lc,st,mid,l,r);
        int q2 = query(rc,mid+1,en,l,r);

        return q1 + q2;
}

/// segtree ends///

int n;          /// node number
int par[mxn];   /// parent of nodes
int szz[mxn];   /// size of subtree
vi v[mxn];      /// The graph
int depth[mxn]; /// depth from root
int nxt[mxn];   /// Next node of the chain


/// dfs to calculate the subtree size
void dfs(int n,int pp = 0)
{
	par[n] = pp;
	szz[n] = 1;

	For(i,v[n].sz)
	{
		int vv = v[n][i];
		if(vv==pp)
			continue;
		depth[vv] = depth[n] + 1;

		dfs(vv,n);

		szz[n] += szz[vv];


		/// next node of chain is the heaviest child
		if(nxt[n] == -1 || szz[vv] > szz[nxt[n]])
			nxt[n] = vv;
	}
}

int chain[mxn]; /// which chain a node belongs to
int num[mxn];   /// The changed node number
int csz[mxn];   /// chain i size
int top[mxn];   /// top node of the chain i
int cnt = 1;    /// the count of chains
int all;        /// For changing node numbers

/// constructing chain
void hld(int n,int pp = -1)
{
	chain[n] = cnt - 1;

	num[n] = all++;

	/// if chain size zero top of the chain (cnt-1) is node n
	if(!csz[cnt-1])
		top[cnt-1] = n;

	csz[cnt-1]++;

	/// go down this chain
	if( nxt[n] != -1)
		hld(nxt[n],n);

	For(i,v[n].sz)
	{
		int vv = v[n][i];
		if(vv == pp || vv == nxt[n])
			continue;

		cnt++;

		/// going the other child to build other chains
		hld(vv,n);
	}
}




int tot[mxn];    /// max of chain i

/// Getting result from a to b
/// For this problem we are getting max

int go(int a,int b)
{
        int ans = 0;
        while( chain[a] != chain[b])
        {
                /// we want the node with more depth chain in variable a
                if(depth[top[chain[a]]] < depth[top[chain[b]]] )
                        swap(a,b);

                int start = top[chain[a]];

                /// if full chain is included
                if(num[a] == num[start] + csz[chain[a]] - 1)
                        ans +=  tot[chain[a]];
                else
                        ans +=  query(1,1,n,num[start],num[a]);

                a = par[start];
        }

        if(depth[a] > depth[b])
                swap(a,b);

        ans += query(1,1,n,num[a],num[b]);

        return ans;
}



/// changing value of node n to val or increase val
/// handle in the seg tree functions

void modify(int node,int val)
{
        update(1,1,n,num[node],val);

        int st = num[top[chain[node]]];
        int en = st + csz[chain[node]] - 1;

        tot[chain[node]] = query(1,1,n,st,en);
}


void ini()
{
	mem(nxt,-1);
	mem(v,NULL);
	mem(csz,0);
	cnt = 2;
	all = 1;
}


int genie[mxn];

int main()
{

        int t,cs = 1 , a , b,q,op;
        sf(t);
        while(t--)
        {
                ini();
                sf(n);
                Fre(i,1,n+1)
                        sf(genie[i]);

                For(i,n-1)
                {
                        sff(a,b);
                        a++;
                        b++;
                        v[a].pb(b);
                        v[b].pb(a);
                }

                dfs(1);
                hld(1);

                Fre(i,1,n+1)
                        modify(i,genie[i]);

                sf(q);

                CASE(cs++);
                while(q--)
                {
                        sfff(op,a,b);
                        a++;
                        b++;
                        if(op)
                        {

                                b--;
                                modify(a,b);
                        }
                        else
                                pfn(go(a,b));

                }
        }

	return 0;
}


