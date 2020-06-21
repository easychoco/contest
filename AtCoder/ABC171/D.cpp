#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

void solve()
{
	int n, input;
	cin >> n;
	vector<int> a(100001, 0);
	for(int i = 0; i < n; ++i)
	{
		cin >> input;
		a[input]++;
	}

	ll ans = 0;
	for(int i = 0; i <= 100001; ++i)
	{
		ans += a[i] * i;
	}

	int q, b, c;
	cin >> q;
	for(int i = 0; i < q; ++i)
	{
		cin >> b >> c;
		ans += (c - b) * a[b];
		a[c] += a[b];
		a[b] = 0;
		cout << ans << endl;
	}
}

int main()
{
	fastio;
	solve();

	return 0;
}