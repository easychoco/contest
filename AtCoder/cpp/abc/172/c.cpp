#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
	ll n, m, k;
	cin >> n >> m >> k;
	vector<ll> a(n + 1, 0);
	vector<ll> b(m + 1, 0);

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		a[i] += a[i - 1];
	}
	for(int i = 1; i <= m; ++i)
	{
		cin >> b[i];
		b[i] += b[i - 1];
	}

	int ans = 0;
	for(int i = 0; i <= n; ++i)
	{
		if (k - a[i] < 0) continue;
		auto b_iter = upper_bound(b.begin(), b.end(), k - a[i]);
		int b_ind = distance(b.begin(), b_iter);
		ans = max(ans, i + b_ind - 1);
	}
	cout << ans;
}

int main()
{
	fastio;
	solve();

	return 0;
}