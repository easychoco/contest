#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

// a^n % mod を計算する O(log n)
ll powmod(ll a, ll n, ll mod) {
	ll ret = 1;
	while (n > 0) {
		if (n % 2 == 1) { ret = ret * a % mod; }
		a = a * a % mod;
		n /= 2;
	}
	return ret;
}

// nCr % mod を計算する O(r)
ll combmod(ll n, ll r, ll mod) {
	ll x = 1, y = 1;
	r = min(n - r, r);
	for(ll i = 0; i < r; ++i) { x = x * (n - i) % mod; }	// 分子
	for(ll i = 1; i <= r; ++i) { y = y * i % mod; }			// 分母
	return x * powmod(y, mod - 2, mod) % mod;	// nCr = (分子) * (分母)^-1 mod M
}

void solve()
{
	ll x, y;
	cin >> x >> y;
	
	if ((x + y) % 3 != 0)
	{
		cout << 0;
		return;
	}

	if (x > 2 * y || y > 2 * x)
	{
		cout << 0;
		return;
	}

	ll a = (2 * y - x) / 3LL;
	ll b = (2 * x - y) / 3LL;

	cout << combmod(a + b, min(a, b), MOD);
}

int main()
{
	fastio;
	solve();

	return 0;
}