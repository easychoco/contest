#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

void solve()
{
	ll h;
	cin >> h;

	int log2 = 0;
	while(h > 0)
	{
		h /= 2;
		log2++;
	}
	ll ans = pow(2, log2) - 1;
	cout << ans;
}

int main()
{
	fastio;
	solve();

	return 0;
}