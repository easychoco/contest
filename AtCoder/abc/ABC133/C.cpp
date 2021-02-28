#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
	ll l, r;
	cin >> l >> r;
	if (r - l >= 2019)
	{
		cout << 0;
		return;
	}
	l %= 2019LL;
	r %= 2019LL;
	if (l >= r) r += 2019LL;

	int ans = (l * r) % 2019;
	for(int i = l; i <= r - 1; ++i)
	{
		for(int j = i + 1; j <= r; ++j)
		{
			ans = min(ans, (i * j) % 2019);
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