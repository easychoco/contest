#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

constexpr int INF = 1 << 30;

struct Edge {
    int from;	//出発点
    int to;		//到達点
    int cost;	//移動コスト
};

vector<int> to[2505];
vector<int> reverse_to[2505];
bool ok[2505];
bool reachableFrom1[2505];
bool reachableFromN[2505];

void dfs(int v)
{
	if (reachableFrom1[v])
	{
		return;
	}
	reachableFrom1[v] = true;

	for(const auto& u : to[v])
	{
		dfs(u);
	}
}

void dfs_reverse(int v)
{
	if (reachableFromN[v])
	{
		return;
	}
	reachableFromN[v] = true;

	for(const auto& u : reverse_to[v])
	{
		dfs_reverse(u);
	}
}


void solve()
{
	fill(ok, ok + 2505, false);
	fill(reachableFrom1, reachableFrom1 + 2505, false);
	fill(reachableFromN, reachableFromN + 2505, false);

	int n, m, p;
	cin >> n >> m >> p;

	vector<Edge> edges;
	vector<int> dist(n, INF);
	dist[0] = 0;

	for(int i = 0; i < m; ++i)
	{
		Edge edge;
		cin >> edge.from >> edge.to >> edge.cost;
		edge.from--;
		edge.to--;
		edge.cost -= p;
		edge.cost *= -1; // コストを反転させて最短経路問題を解けば、最長経路になる

		edges.emplace_back(edge);

		to[edge.from].emplace_back(edge.to);
		reverse_to[edge.to].emplace_back(edge.from);
	}

	dfs(0);
	dfs_reverse(n - 1);
	for(int i = 0; i < n; ++i)
	{
		ok[i] = reachableFrom1[i] & reachableFromN[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			Edge e = edges[j];
			if(!ok[e.to]) continue;
			if(!ok[e.from]) continue;

			if (dist[e.to] > dist[e.from] + e.cost)
			{
				dist[e.to] = dist[e.from] + e.cost;
				if (i == n - 1)
				{
					cout << -1;
					return;
				}
			}
		}
	}
	cout << max(dist[n - 1] * -1, 0);
}

int main()
{
	fastio;
	solve();

	return 0;
}