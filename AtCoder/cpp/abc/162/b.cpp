#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;


void solve()
{
	int n;
	cin >> n;

	ll ans = 0;
	for(int i = 1; i <= n; ++i)
	{
		if((i % 3) * (i % 5) > 0)
		{
			ans += i;
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