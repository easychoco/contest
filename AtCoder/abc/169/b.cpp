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

	ll ans = 1;
	for(int i = 0; i < n; ++i)
	{
		ll a;
		cin >> a;

		if (a == 0)
		{
			cout << 0;
			return;
		}
		if (ans > LLONG_MAX / a || 1000000000000000000 < ans * a)
		{
			for (int j = i; j < n; ++j)
			{
				ll b;
				cin >> b;
				if (b == 0)
				{
					cout << 0;
					return;
				}
			}
			cout << -1;
			return;
		}
		ans *= a;
	}
	cout << ans;
}

int main()
{
	fastio;
	solve();

	return 0;
}