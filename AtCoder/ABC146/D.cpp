#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

void solve()
{
	int n;
	cin >> n;

	vector< pair<int, int> > edge;
	vector< vector<int> > node(n, vector<int>());
	int a, b;
	for(int i = 0; i < n - 1; ++i)
	{
		cin >> a >> b;
		a--; b--;
		edge.emplace_back(make_pair(a, b));
		node[a].emplace_back(b);
		node[b].emplace_back(a);
	}

	int max_color = 0;
	for(const auto& v : node)
	{
		max_color = max(max_color, (int)v.size());
	}
	cout << max_color << endl;

	queue<int> que;
	que.push(0);
	while(!que.empty())
	{
		int cnt = 0;
		int node = que.front(); que.pop();
		for(const auto& next : node)
		{
			node_color[v].insert()
			que.push(v);
		}

	}
}

int main()
{
	fastio;
	solve();

	return 0;
}