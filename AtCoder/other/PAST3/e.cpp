#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

void solve()
{
	int n, m, q;
	cin >> n >> m >> q;

	vector<int> node(n, 0);
	vector< vector<int> > edge(n, vector<int>(0));

	int v, u;
	for(int i = 0; i < m; ++i)
	{
		cin >> v >> u;
		v--;
		u--;
		edge[v].emplace_back(u);
		edge[u].emplace_back(v);
	}

	int c;
	for(int i = 0; i < n; ++i)
	{
		cin >> c;
		node[i] = c;
	}

	int s, x, y;
	for(int i = 0; i < q; ++i)
	{
		cin >> s >> x;
		x--;
		cout << node[x] << endl;
		if (s == 1)
		{
			for(auto& v : edge[x])
			{
				node[v] = node[x];
			}
		}
		else
		{
			cin >> y;
			node[x] = y;
		}
		
	}

}

int main()
{
	fastio;
	solve();

	return 0;
}