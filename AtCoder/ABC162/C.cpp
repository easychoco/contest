#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

void solve()
{
	int k;
	cin >> k;
	ll ans = 0;
	for(int a = 1; a <= k; ++a )
	{
		for(int b = 1; b <= k; ++b )
		{
			int gcd_ab = gcd(a, b);
			for(int c = 1; c <= k; ++c )
			{
				ans += gcd(gcd_ab, c);
			}
		}
	}
	cout << ans << endl;
}

int main()
{
	fastio;
	solve();

	return 0;
}