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
	vector<ll> a(n + 1);
	vector<ll> b(n);
	for(int i = 0; i < n + 1; ++i)
	{
		cin >> a[i];
	}
	for(int i = 0; i < n; ++i)
	{
		cin >> b[i];
	}

	ll ans = 0;
	for(int i = 0; i < n; ++i)
	{
		if (a[i] <= b[i])
		{
			ans += min(b[i], a[i] + a[i + 1]);
			a[i + 1] = max(0LL, a[i + 1] + a[i] - b[i]);
		}
		else
		{
			ans += b[i];
		}	
	}
	cout << ans;
}

int main()
{
	fastio;
	solve();

	return 0;
}