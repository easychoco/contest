#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

void solve()
{
	ll a, b, c, k;
	cin >> a >> b >> c >> k;

	k -= a;
	if (k <= 0) {
		cout << k + a << endl;
		return;
	}
	k -= b;
	if (k <= 0) {
		cout << a;
	}
	else
	{
		cout << a - k;
	}
	cout << endl;
}

int main()
{
	fastio;
	solve();

	return 0;
}