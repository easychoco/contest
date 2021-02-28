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
	if (n & 1)
	{
		cout << 0;
		return;
	}

	ll ans = 0;

	// 5 の個数を数える
	ll five_pow = 5;
	while(five_pow < n)
	{
		ans += n / five_pow / 2;
		five_pow *= 5;
	}
	cout << ans;
}

int main()
{
	fastio;
	solve();

	return 0;
}