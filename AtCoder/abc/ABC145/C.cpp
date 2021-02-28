#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

int n;
double dist[8][8];

double dfs(int visited, int now, double total_dist)
{
	if (visited == ((1 << n) - 1))
	{
		return total_dist;
	}

	double ret = 0.0;
	for(int i = 0; i < n; ++i)
	{
		if((visited & (1 << i)) == 0)
		{
			ret += dfs(visited | (1 << i), i, total_dist + dist[now][i]);
		}
	}

	return ret;
}

void solve()
{
	cin >> n;
	vector<int> x(n);
	vector<int> y(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> x[i] >> y[i];
	}

	for(int i = 0; i < n; ++i)
	{
		for(int j = i; j < n; ++j)
		{
			dist[i][j] = dist[j][i] = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
		}
	}

	double ans = 0.0;
	for(int i = 0; i < n; ++i)
	{
		ans += dfs(1 << i, i, 0);
	}
	double factor = 1.0;
	for(int i = 1; i <= n; ++i)
	{
		factor *= i;
	}
	printf("%.7f\n", ans / factor);
}

int main()
{
	fastio;
	solve();

	return 0;
}