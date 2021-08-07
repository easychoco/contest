#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

void solve()
{
	ll n, a, b;
	cin >> n >> a >> b;

	if ((b - a) % 2 == 0)
	{
		cout << (b - a) / 2 << endl;
		return;
	}

	ll move_cnt = 0;
	if (a - 1 < n - b)
	{
		move_cnt += a;
		b -= a;
		a = 1;
	}
	else
	{
		move_cnt += n - b + 1;
		a += n - b + 1;
		b = n;
	}
	
	cout << move_cnt + (b - a) / 2 << endl;

}

int main()
{
	fastio;
	solve();

	return 0;
}