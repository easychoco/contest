#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

void solve()
{
	ll a;
	double in;
	cin >> a >> in;
	ll b = (in + 0.001) * 100;
	ll ans = (a * b) / 100;
	cout << ans;
}

int main()
{
	fastio;
	solve();

	return 0;
}