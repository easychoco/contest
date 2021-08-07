#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;


void solve()
{
	const ll INF = 1LL << 60;
	ll cost[301][301];
	ll tank[301][301];

	ll n, m, l;
	cin >> n >> m >> l;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			cost[i][j] = INF;
		}
		cost[i][i] = 0;
	}

	ll a, b, c;
	for(int i = 0; i < m; ++i)
	{
		cin >> a >> b >> c;
		a--; b--;
		cost[a][b] = cost[b][a] = c;
	}

	for (int k = 0; k < n; k++){			// 経由する頂点
		for (int i = 0; i < n; i++) {		// 始点
			for (int j = 0; j < n; j++) {	// 終点
				cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
			}
		}
	}

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			tank[i][j] = (cost[i][j] <= l) ? 1 : INF;
		}
	}

	for (int k = 0; k < n; k++){			// 経由する頂点
		for (int i = 0; i < n; i++) {		// 始点
			for (int j = 0; j < n; j++) {	// 終点
				tank[i][j] = min(tank[i][j], tank[i][k] + tank[k][j]);
			}
		}
	}

	int q;
	cin >> q;
	int s, t;
	for(int i = 0; i < q; ++i)
	{
		cin >> s >> t;
		s--; t--;
		cout << (tank[s][t] == INF ? -1 : tank[s][t] - 1) << endl;
	}
}

int main()
{
	fastio;
	solve();

	return 0;
}