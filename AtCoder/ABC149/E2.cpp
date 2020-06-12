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
	sort(a.begin(), a.end());

	int le = 0;
	int re = m + 1;

	while(re - le > 1)
	{
		int mid = (le + re) / 2;
		int num = 0;

		for(int i = 0; n - 1; i >= 0; --i)
		{
			
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