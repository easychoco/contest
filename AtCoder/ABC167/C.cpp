#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

void solve()
{
	int n, m, x;
	cin >> n >> m >> x;
	int c[12];
	int a[12][12] = {};
	for(int i = 0; i < n; ++i)
	{
		cin >> c[i];
		for(int j = 0; j < m; ++j)
		{
			cin >> a[i][j];
		}
	}

	const ll initial_num = 1000000000000;
	ll ans = initial_num;
	for(int i = 0; i < 1 << n; ++i)
	{
		int total[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
		ll cost = 0;
		for(int j = 0; j < n; ++j)
		{
			if (i & 1 << j)
			{
				for(int k = 0; k < m; ++k)
				{
					total[k] += a[j][k];
				}
				cost += c[j];
			}
		}
		bool ok = true;
		for(int j = 0; j < m; ++j)
		{
			ok = ok & total[j] >= x;
		}
		if (ok)
		{
			ans = min(ans, cost);
		}

	}

	if (ans == initial_num)
	{
		ans = -1;
	}
	cout << ans << endl;
}

int main()
{
	fastio;
	solve();

	return 0;
}