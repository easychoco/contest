#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

void solve()
{
	int k, n;
	cin >> k >> n;
	vector<int> a(n * 2);

	cin >> a[0];
	for(int i = 1; i < n; ++i)
	{
		cin >> a[i];
		a[i] -= a[0];
	}
	a[0] = 0;

	int ans = k - a[n - 1];
	for(int i = n - 1; i >= 1; --i)
	{
		ans = max(ans, a[i] - a[i - 1]);
	}

	cout << k - ans << endl;
}

int main()
{
	fastio;
	solve();

	return 0;
}