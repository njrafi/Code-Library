/*
Idea:

1. Store back hash in lca style
2. Store Front hash in normal rolling hash style
3. hashOfPath(a,b) = backHashOf(a,lca) + frontHashOf(lca,b)

*/


#define mxn 200005
#define p1 163
#define p2 167
#define mod1 1000000007
#define mod2 1000000009
#define ui64 unsigned long long int


vector< vector<int>> cnt(mxn, vector<int>(62,0));

int value[mxn];
vi v[mxn];
int p[mxn][23];
int l[mxn];
i64 p1Power[mxn];
i64 p2Power[mxn];

// back hash
i64 hash1[mxn][23];
i64 hash2[mxn][23];


// front hash
i64 roll1[mxn];
i64 roll2[mxn];

// p[x][y] means 2^y th parent of x
// hash[x][y] means hash from x to before 2^y


// determing the level of the nodes
void dfs(int s,int par,int lev) {
	p[s][0] = par;
	hash1[s][0] = value[s];
	hash2[s][0] = value[s];

        if(par != -1) {
                cnt[s] = cnt[par];
        }
        cnt[s][value[s]]++;

        if(par != -1) {
                roll1[s] = roll1[par] * p1 + value[s];
                roll2[s] = roll2[par] * p2 + value[s];
        } else {
                roll1[s] = value[s];
                roll2[s] = value[s];
        }

        roll1[s] %= mod1;
        roll2[s] %= mod2;

	l[s] = lev;
	For(i,v[s].sz)
                if(l[v[s][i]]==-1)
                        dfs(v[s][i], s, lev+1 );
}

void gen_table(int n) {
	mem(p,-1);
	mem(l,-1);
        For(i,n + 1)
                For(j,cnt[i].sz)
                        cnt[i][j] = 0;
	dfs(1,-1,0);

	p1Power[0] = 1;
	p2Power[0] = 1;
	Fre(i,1,mxn) {
                p1Power[i] = (p1Power[i-1] * p1) % mod1;
                p2Power[i] = (p2Power[i-1] * p2) % mod2;
	}
	// (1<<j) = po(2,j)
	for(int j = 1 ; (1<<j) < n ; j++)
		Fre(i,1,n+1)
                        if(p[i][j-1]!=-1) {
                                p[i][j] = p[p[i][j-1]][j-1];

                                hash1[i][j] = hash1[i][j-1] * p1Power[1 << (j-1)] + hash1[p[i][j-1]][j-1];
                                hash2[i][j] = hash2[i][j-1] * p2Power[1 << (j-1)] + hash2[p[i][j-1]][j-1];
                                hash1[i][j] %= mod1;
                                hash2[i][j] %= mod2;
                        }



}


pair<i64,i64> getBackHash(int from,int to) {
        i64 h1 = 0;
        i64 h2 = 0;
        int hi = log2(l[from]) + 2;

        for(int i = hi ; i >= 0 ; i--)
                if(l[from] - (1<<i) >= l[to]) {
                        h1 = h1 * p1Power[1 << i] + hash1[from][i];
                        h1 %= mod1;

                        h2 = h2 * p2Power[1 << i] + hash2[from][i];
                        h2 %= mod2;

                        from = p[from][i];
                }

        return {h1,h2};
}

int getLca(int uu,int vv) {
	if(l[uu]<l[vv])
		swap(uu,vv);

	int hi = log2(l[uu]) + 2;


	// bring both node to same level
	for(int i = hi ; i >= 0 ; i--)
		if(l[uu] - (1<<i) >= l[vv])
			uu = p[uu][i];

	if(uu==vv)
		return uu;


	for(int i = hi ; i >= 0 ; i--)
		if(p[uu][i]!=-1 && p[uu][i]!=p[vv][i]) {
			uu = p[uu][i];
			vv = p[vv][i];
		}

	return p[uu][0];
}


pair<i64,i64> getHashOfPath(int a,int b) {
        int lca = getLca(a,b);

        auto hashFromAToLca = getBackHash(a,lca);

        int lengthFromLcaToB = l[b] - l[lca] ;

        i64 hash1FromLcaToB = ((roll1[b] - roll1[lca] * p1Power[lengthFromLcaToB]) % mod1 + mod1 ) % mod1 ;
        i64 hash2FromLcaToB = ((roll2[b] - roll2[lca] * p2Power[lengthFromLcaToB]) % mod2 + mod2 ) % mod2 ;

        i64 h1 = hashFromAToLca.ff * p1Power[ lengthFromLcaToB + 1] + value[lca] * p1Power[ lengthFromLcaToB  ] + hash1FromLcaToB;
        i64 h2 = hashFromAToLca.ss * p2Power[ lengthFromLcaToB + 1] + value[lca] * p2Power[ lengthFromLcaToB ] + hash2FromLcaToB;

        h1 %= mod1;
        h2 %= mod2;


//        cerr << a << " to " << b << endl;
//        cerr << hashFromAToLca.ff << " " << hash1FromLcaToB << endl;
//        cerr << hashFromAToLca.ss << " " << hash2FromLcaToB << endl;
//        cerr << h1 << " " << h2 << endl;
//
//        cerr << endl;
        return {h1,h2};
}

bool canMakePalin(int a,int b) {
        int lca = getLca(a,b);
        int totalValue = 0;
        int singleValue = 0;

        Fre(val,1,60 + 1) {
                int cntHere = cnt[a][val] - cnt[lca][val] + cnt[b][val] - cnt[lca][val] + (value[lca] == val);

                totalValue += cntHere;
                totalValue %= 2;
                singleValue += cntHere % 2;

        }


        return (totalValue == singleValue);

}

int main() {

	int t,n,a,b,cs = 1;
	sf(t);
	while(t--) {
		mem(v,NULL);
		sf(n);
		Fre(i,1,n+1) {
		        sf(value[i]);
		}
		For(i,n-1) {
			sff(a,b);
			v[a].pb(b);
			v[b].pb(a);
		}

		gen_table(n);


                CASE(cs++);
		int op,q,c,d;
		sf(q);
		while(q--) {
                        sf(op);
                        if(op == 1) {
                                sff(a,b);
                                if(canMakePalin(a,b)) puts("YES");
                                else puts("NO");
                        }
                        else if(op==2) {
                                sff(a,b);
                                if(getHashOfPath(a,b) == getHashOfPath(b,a)) puts("YES");
                                else puts("NO");
                        } else {
                                sff(a,b);
                                sff(c,d);
                                if(getHashOfPath(a,b) == getHashOfPath(c,d)) puts("YES");
                                else puts("NO");
                        }
		}

	}











	return 0;
}



