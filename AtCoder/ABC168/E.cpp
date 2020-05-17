#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

ll powmod(ll a, ll n, ll mod)
{
	ll ret = 1;
	while (n > 0)
	{
		if (n % 2 == 1)
		{
			ret = ret * a % mod;
		}
		a = a * a % mod;
		n /= 2;
	}
	return ret;
}


void solve()
{
	int n;
	cin >> n;

	map<pair<ll, ll>, ll> m;

	for(int i = 0; i < n; ++i)
	{
		ll a, b;
		cin >> a >> b;

		ll gcd_ab = gcd(a, b);

		pair<ll, ll> p = make_pair(a / gcd_ab, b / gcd_ab);
		m[p]++;
	}

	for(auto itr = m.begin(); itr != m.end(); ++itr)
	{
		cout << itr->first.first << " " << itr->first.second <<  " : " << itr->second << endl;
	}
	ll match = 0;

	ll diff = 0;

	for(auto itr = m.begin(); itr != m.end(); ++itr)
	{
		pair<ll, ll> p1 = make_pair(-itr->first.second, itr->first.first);
		if (m.count(p1) > 0)
		{
			match += m[p1];
			diff += itr->second * m[p1];
		}

		pair<ll, ll> p2 = make_pair(itr->first.second, -itr->first.first);
		if (m.count(p2) > 0)
		{
			match += m[p2];
			diff += itr->second * m[p2];
		}
	}

	ll ans = n;
	ans += n * (n - 1) / 2;
	ans -= diff / 2;
	ans += match * match * (match - 1) / 2;

	cout << diff << endl;
	cout << match << endl;
	cout << ans << endl;
	// return;

	ll non_match = n - match;

	ans += (6 * powmod(2, non_match, MOD)) % MOD;
	ans -= (1 + non_match + (non_match * (non_match - 1) / 2) % MOD);

	cout << ans;

}

int main()
{
	fastio;
	solve();

	return 0;
}