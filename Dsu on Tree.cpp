/*
Assuming we have a tree

we want to ans:

How many vertices in the subtree of vertex v has some property

in (nlogn) for all the queries

First we calculate the subtree of every vertice

Then we call the dfs

modify the "" cnt[ col[v] ]++ "" parts

The code is for

Given a tree, every vertex has color.
Query is how many vertices in subtree of vertex v are colored with color c

*/


#define mxn 100005

int ssz[mxn];
vi g[mxn];

/// Getting subtree size
void getsz(int v, int p)
{
	ssz[v] = 1;
	for(auto u : g[v])
		if(u != p)
		{
			getsz(u, v);
			ssz[v] += ssz[u];
		}
}

/// Vector pointer
vi *vec[mxn];


/// These are problem specifiq
int cnt[mxn];
int col[mxn];


void dfs(int v, int p, bool keep)
{
	int mx = -1, bigChild = -1;
	for(auto u : g[v])
		if(u != p && ssz[u] > mx)
                {
			mx = ssz[u];
                        bigChild = u;
                }

	for(auto u : g[v])
		if(u != p && u != bigChild)
			dfs(u, v, 0);

	if(bigChild != -1)
	{

		dfs(bigChild, v, 1);
		vec[v] = vec[bigChild];
	}
	else
		vec[v] = new vi();

	vec[v]->push_back(v);

	cnt[ col[v] ]++;

	for(auto u : g[v])
		if(u != p && u != bigChild)
			for(auto x : *vec[u])
			{
				cnt[ col[x] ]++;
				vec[v] -> push_back(x);
			}
	// now cnt[v][c] is the number of vertices in subtree of vertex v that has color c. You can answer the queries easily.
	// note that in this step *vec[v] contains all of the subtree of vertex v.

	if(keep == 0)
		for(auto u : *vec[v])
			cnt[ col[u] ]--;
}



