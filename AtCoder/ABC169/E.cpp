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
	vector<ll> a(n);
	vector<ll> b(n);

	for(int i = 0; i < n; ++i)
	{
		cin >> a[i] >> b[i];
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	ll center_a = (n & 1) ? a[n / 2] : (a[n / 2 - 1] + a[n / 2]);
	ll center_b = (n & 1) ? b[n / 2] : (b[n / 2 - 1] + b[n / 2]);

	cout << abs(center_b - center_a) + 1;
}

int main()
{
	fastio;
	solve();

	return 0;
}