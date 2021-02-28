#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

void solve()
{
	int n, u, v;
	cin >> n >> u >> v;
	u--; v--;

	vector< vector<int> > node(n, vector<int>() );
	vector<int> dist_u(n, -1);
	vector<int> dist_v(n, -1);

	int a, b;
	for(int i = 0; i < n - 1; ++i)
	{
		cin >> a >> b;
		a--; b--;
		node[a].emplace_back(b);
		node[b].emplace_back(a);
	}

	queue<int> que;
	que.push(u);

	dist_u[u] = 0;

	// グラフは木 つまり閉路はない
	// BFSで経路長探索
	while(!que.empty())
	{
		int now = que.front();
		que.pop();
		for(const auto& next : node[now])
		{
			if (dist_u[next] == -1)
			{
				dist_u[next] = dist_u[now] + 1;
				que.push(next);
			}
		}
	}

	// queはemptyだから使いまわせる...けれどこれは関数化したい
	que.push(v);
	dist_v[v] = 0;

	while(!que.empty())
	{
		int now = que.front();
		que.pop();
		for(const auto& next : node[now])
		{
			if (dist_v[next] == -1)
			{
				dist_v[next] = dist_v[now] + 1;
				que.push(next);
			}
		}
	}

	int ans = -1;
	for(int i = 0; i < n; ++i)
	{
        if(dist_u[i] < dist_v[i])
		{
	        ans = max(ans, dist_v[i]);
		}
	}

	cout << ans - 1;
}

int main()
{
	fastio;
	solve();

	return 0;
}