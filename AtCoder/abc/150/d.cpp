#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

// 最大公約数 : 3,4 ->  1
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

// 最小公倍数 : 3,4 -> 12
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

void solve()
{
	ll n, m;
	cin >> n >> m;
	vector<int> a(n);

	ll a_lcm = 1;
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
		if (a[i] / 2 / gcd(a[i] / 2, a_lcm) > m / a_lcm)
		{
			cout << 0;
			return;
		}
		a_lcm = lcm(a[i] / 2, a_lcm);
	}

	for(int i = 0; i < n; ++i)
	{
		if (a_lcm % a[i] == 0)
		{
			cout << 0;
			return;
		}
	}

	ll ans = ((m - a_lcm) / (a_lcm * 2)) + 1;
	cout << ans;

}

int main()
{
	fastio;
	solve();

	return 0;
}