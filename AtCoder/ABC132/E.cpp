#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;


vector<int> edge[100005];
bool seen[100005];

set<int> dfs(int now, int depth)
{
	if (depth == 3)
	{
		set<int> ret;
		for(const int e : edge[now])
		{
			ret.insert(e);
		}
		return ret;
	}

	set<int> ret;
	for(const int e : edge[now])
	{
		set<int> next = dfs(e, depth + 1);
		for(const int n : next) ret.insert(n);
	}
	return ret;
}

void solve()
{
	fill(seen, seen + 100005, false);
	int n, m, u, v;;
	cin >> n >> m;

	for(int i = 0; i < m; ++i)
	{
		cin >> u >> v;
		u--; v--;
		edge[u].emplace_back(v);
	}

	int start, dest;
	cin >> start >> dest;
	start--; dest--;

	set<int> now{ start };
	int cnt = 0;
	while(true)
	{
		cnt++;
		set<int> next;
		for(const int e : now)
		{
			set<int> to = dfs(e, 1);
			for(const auto& t : to)
			{
				//cout << t << " ";
				next.insert(t);
				if (t == dest)
				{
					cout << cnt;
					return;
				}
			}
			//cout << endl;
		}

		now = next;
		bool ng = true;
		for(const int e : now)
		{
			ng &= seen[e];
			seen[e] = true;
		}
		if (ng)
		{
			cout << -1;
			return;
		}
	}
}

int main()
{
	fastio;
	solve();

	return 0;
}