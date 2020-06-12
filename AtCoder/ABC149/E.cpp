#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

void solve()
{
	ll n, m;
	cin >> n >> m;

	vector<ll> a(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	priority_queue<int> sum;

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			sum.push(a[i] + a[j]);
		}
	}

	ll ans = 0;
	for(int i = 0; i < m; ++i)
	{
		ans += sum.top();
		sum.pop();
	}
	cout << ans;
}

int main()
{
	fastio;
	solve();

	return 0;
}