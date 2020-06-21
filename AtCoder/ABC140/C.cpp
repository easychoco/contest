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
	vector<int> b(n);
	for(int i = 0; i < n - 1; ++i)
	{
		cin >> b[i];
	}

	int ans = b[0];
	for(int i = 1; i < n - 1; ++i)
	{
		ans += min(b[i - 1], b[i]);
	}
	ans += b[n - 2];

	cout << ans;
}

int main()
{
	fastio;
	solve();

	return 0;
}