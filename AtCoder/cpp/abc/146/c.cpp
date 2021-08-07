#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

ll a, b, x;

ll calc(ll n)
{
	ll ret = a * n;

	ll log10 = 1;
	while(n /= 10, n > 0)
	{
		log10++;
	}

	return ret + b * log10;
}

void solve()
{
	cin >> a >> b >> x;

	ll le = 0, re = x / a;
	while(re - le > 1)
	{
		ll mid = (le + re) / 2;
		if ( x < calc(mid) ) re = mid;
		else le = mid;
	}

	cout << min(le, 1000000000LL);
}

int main()
{
	fastio;
	solve();

	return 0;
}