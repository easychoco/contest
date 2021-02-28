#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

void solve()
{
	int n, k;
	cin >> n >> k;

	vector<ll> p(n + 2, 0);

	for(int i = 0; i < n; ++i)
	{
		cin >> p[i];
	}

	ll val = 0;
	for(int i = 0; i < k; ++i)
	{
		val += p[i];
	}

	ll ans = val;
 	for(int i = 0; i < n - k; ++i)
	{
		val = val - p[i] + p[i + k];
		ans = max(ans, val);
	}

	printf("%.7lf\n", (double)(k + ans) / 2.0);
}

int main()
{
	fastio;
	solve();

	return 0;
}