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

	vector<ll> a(n + 1, 0);
	vector<ll> b(n + 1, 0);
	vector<ll> c(n + 1, 0);
	ll ans = 0;
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
		a[i]--;
		b[a[i]]++;
	}

	for(int i = 0; i < n; ++i)
	{
		c[i] = (b[i] * (b[i] - 1)) / 2;
		ans += c[i];
	}

	for(int i = 0; i < n; ++i)
	{
		cout << ans - c[a[i]] + ((b[a[i]] - 1) * (b[a[i]] - 2)) / 2 << endl;
		//cout << " " << ans << " - " << c[a[i]] << " + " << ((b[a[i]] - 1) * (b[a[i]] - 2)) / 2 << endl;
	}


}

int main()
{
	fastio;
	solve();

	return 0;
}