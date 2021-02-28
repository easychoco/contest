#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
	int n;
	cin >> n;

	ll ans = 0;
	for(int i = 1; i <= n; ++i)
	{
		for(int j = i; j <= n; j += i)
		{
			ans += j;
		}
	}
	cout << ans;
}

int main()
{
	fastio;
	solve();

	return 0;
}