#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

#define Rad2Deg 180.0 / PI

void solve()
{
	double a, b, x;
	cin >> a >> b >> x;
	double v = a * a * b;

	if (x < v / 2.0)
	{
		printf("%.7f\n", atan2(a * b * b, 2.0 * x) * Rad2Deg);
	}
	else
	{
		printf("%.7f\n", atan2(2.0 * (a * b - x / a), a * a) * Rad2Deg);
	}
}

int main()
{
	fastio;
	solve();

	return 0;
}