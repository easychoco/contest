#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

void solve()
{
	ll n;
	cin >> n;

	ll ans = n + 1;
	for(ll i = 2; i * i <= n; ++i)
	{
		if (n % i == 0)
		{
			ans = min(ans, i + n / i);
		}
	}
	cout << ans - 2;
}

int main()
{
	fastio;
	solve();

	return 0;
}