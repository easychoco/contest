#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

void solve()
{
	int n;
	cin >> n;
	map<ll, ll> b;

	ll ans = 0;
	for(ll i = 0; i < n; ++i)
	{
		ll a;
		cin >> a;
		b[i + 1 + a]++;
		if (b[i + 1 - a] > 0)
		{
			ans += b[i + 1 - a];
		}
	}
	cout << ans << endl;
}

int main()
{
	fastio;
	solve();

	return 0;
}