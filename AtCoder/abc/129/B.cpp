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
	vector<int> w(n);
	int g1 = 0;
	int g2 = 0;
	for(int i = 0; i < n; ++i)
	{
		cin >> w[i];
		g2 += w[i];
	}
	int ans = 10000;
	for(int i = 0; i < n; ++i)
	{
		g1 += w[i];
		g2 -= w[i];
		ans = min(ans, abs(g2 - g1));
	}
	cout << ans;
}

int main()
{
	fastio;
	solve();

	return 0;
}