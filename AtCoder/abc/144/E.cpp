#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;



void solve()
{
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	vector<ll> f(n);

	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	for(int i = 0; i < n; ++i)
	{
		cin >> f[i];
	}

	sort(a.begin(), a.end());
	sort(f.begin(), f.end(), greater<int>());

	ll le = -1, re = 1000000000000LL;
	while(re - le > 1)
	{
		ll mid = (le + re) / 2;
		{
			ll tmp_k = 0;
			for(int i = 0; i < n; ++i)
			{
				if (a[i] * f[i] > mid)
				{
					tmp_k += (a[i] * f[i] - mid - 1) / f[i] + 1;
				}
			}
			if (tmp_k <= k) re = mid;
			else le = mid;
		}
	}
	cout << re;
}

int main()
{
	fastio;
	solve();

	return 0;
}