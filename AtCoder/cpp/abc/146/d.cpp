#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;
using P = pair<int, int>;

bool visited[200005];
int max_color = 0;
vector<int> ans(200005, 0);
vector< vector<int> > edge(200005, vector<int>());
map< P, int > edges_pair;

void dfs(int now, int parent_color)
{
	if (visited[now]) return;
	visited[now] = true;

	int color = (parent_color + 1) % max_color;

	for(const auto& next : edge[now])
	{
		if (visited[next]) continue;

		P p = ((now < next) ? P(now, next) : P(next, now));
		ans[edges_pair[p]] = color + 1;
		dfs(next, color);
		color = (color + 1) % max_color;
	}
}

void solve()
{
	fill(visited, visited + 200005, false);
	int n, a ,b;
	cin >> n;

	for(int i = 0; i < n - 1; ++i)
	{
		cin >> a >> b;
		a--; b--;
		edge[a].emplace_back(b);
		edge[b].emplace_back(a);
		if (a > b) swap(a, b);
		edges_pair[P(a, b)] = i;
	}

	for(const auto& e : edge)
	{
		max_color = max(max_color, (int)e.size());
	}
	cout << max_color << endl;

	dfs(0, max_color - 1);
	for(int i = 0; i < n - 1; ++i)
	{
		cout << ans[i] << endl;
	}
}

int main()
{
	fastio;
	solve();

	return 0;
}