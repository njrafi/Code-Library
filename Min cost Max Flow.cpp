/// Min-cost Max-flow using SPFA (Shortest Path Faster Algorithm)
/// 0 Based indexed for directed weighted graphs (for undirected graphs, just add two directed edges)


namespace mcmf
{

        /// Number of edges * 2
		/// Be really careful with this, be GENEROUS

        const int MAX = 5002 * 2;
        const long long INF = inf;

        long long cap[MAX], flow[MAX], cost[MAX], dis[MAX];
        int n, m, s, t, Q[MAX * 100], adj[MAX], link[MAX], last[MAX], from[MAX], visited[MAX];

void init(int nodes, int source, int sink)
{
	m = 0, n = nodes, s = source, t = sink;
	for (int i = 0; i <= n; i++)
		last[i] = -1;
}

/// c = capacity , w = cost
void addEdge(int u, int v, long long c, long long w)
{
	adj[m] = v, cap[m] = c, flow[m] = 0, cost[m] = +w, link[m] = last[u], last[u] = m++;
	adj[m] = u, cap[m] = 0, flow[m] = 0, cost[m] = -w, link[m] = last[v], last[v] = m++;
}

bool spfa()
{
	int i, j, x, f = 0, l = 0;
	for (i = 0; i <= n; i++)
		visited[i] = 0, dis[i] = INF;

	dis[s] = 0, Q[l++] = s;
	while (f < l)
	{
		i = Q[f++];
		for (j = last[i]; j != -1; j = link[j])
		{
			if (flow[j] < cap[j])
			{
				x = adj[j];
				if (dis[x] > dis[i] + cost[j])
				{
					dis[x] = dis[i] + cost[j], from[x] = j;
					if (!visited[x])
					{
						visited[x] = 1;
						if (f && rand() & 7)
							Q[--f] = x;
						else
							Q[l++] = x;
					}
				}
			}
		}
		visited[i] = 0;
	}
	return (dis[t] != INF);
}

pair <long long, long long> solve()
{
	int i, j;
	long long mincost = 0, maxflow = 0;

	while (spfa())
	{
		long long aug = INF;
		for (i = t, j = from[i]; i != s; i = adj[j ^ 1], j = from[i])
		{
			aug = min(aug, cap[j] - flow[j]);
		}
		for (i = t, j = from[i]; i != s; i = adj[j ^ 1], j = from[i])
		{
			flow[j] += aug, flow[j ^ 1] -= aug;
		}
		maxflow += aug, mincost += aug * dis[t];
	}
	return make_pair(mincost, maxflow);
}
}

int main()
{
	int t,cs =  1,n,inp;
	sf(t);
	while(t--)
	{
		sf(n);

		int sou = 0;
		int sink = 2 * n + 1;

		mcmf::init(2*n+2,sou,sink);

		Fre(i,1,n+1)
		{
			mcmf::addEdge(sou,i,1,0);
			mcmf::addEdge(i+n,sink,1,0);
		}

		Fre(i,1,n+1)
                        Fre(j,1,n+1)
                        {
                                sf(inp);
                                mcmf::addEdge(i,n+j,1,-inp);
                        }
		pair<i64,i64> ans = mcmf::solve();

		CASE(cs++);
		pfn(-ans.ff);
//				cout << ans.ff << " " << ans.ss << endl;
	}
}

