#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

vector< vector<int> > edge(200004, vector<int>());
ll counter[200004];
bool seen[200004];

void dfs(int node) // search child
{
	if (seen[node])
	{
		return;
	}
	seen[node] = true;

	for(const auto& e : edge[node])
	{
		if (seen[e]) // 親
		{
			counter[node] += counter[e];
			break;
		}
	}
	for(const auto& e : edge[node])
	{
		if (!seen[e]) // 子
		{
			dfs(e);
		}
	}
}

void solve()
{
	fill(counter, counter + 200004, 0);
	fill(seen, seen + 200004, false);

	ll n, q, a, b, p, x;
	cin >> n >> q;

	for(ll i = 0; i < n - 1; ++i)
	{
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	for(ll i = 0; i < q; ++i)
	{
		cin >> p >> x;
		counter[p] += x;
	}

	dfs(1);

	for(int i = 1; i <= n; ++i)
	{
		cout << counter[i] << " ";
	}
}

int main()
{
	fastio;
	solve();

	return 0;
}