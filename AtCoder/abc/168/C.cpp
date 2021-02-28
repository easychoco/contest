#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

void solve()
{
	double a, b, h, m;
	cin >> a >>b >> h >> m;

	double angle_a = 0.0;
	double angle_b = 0.0;

	angle_a = h * 30.0 + m / 2.0;
	angle_b = m * 6.0;

	double rad_a = angle_a * PI / 180.0;
	double rad_b = angle_b * PI / 180.0;

	double a_x, a_y;
	double b_x, b_y;

	a_x = a * cos(rad_a);
	a_y = a * sin(rad_a);

	b_x = b * cos(rad_b);
	b_y = b * sin(rad_b);

	double ans = pow( pow(a_x - b_x, 2.0) + pow(a_y - b_y, 2.0), 0.5);
	printf("%.10lf\n", ans);
}

int main()
{
	fastio;
	solve();

	return 0;
}