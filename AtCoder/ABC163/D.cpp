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

	// (n+1)Ck + nC(k+1) + ... + (n+1)C(n+1)
	//=(n+1)C(n-k+1) + nC(n-k) + ... + (n+1)C(0)

	ll ans = 0;
	for(ll i = k; i <= n + 1; ++i)
	{
		ans = (ans + (long long)((n+1) * i) % MOD - (long long)(i * i) % MOD + 1) % MOD;
	}

	ans = (ans + MOD) % MOD;

	cout << ans << endl;
}

int main()
{
	fastio;
	solve();

	return 0;
}