#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

void solve()
{
	int a, b;
	cin >> a >> b;

	int min_08 = ceil(12.5 * a);
	int max_08 = min_08 + 12;
	int min_10 = 10 * b;
	int max_10 = min_10 + 9;

	if (min_08 < max_10 && min_10 < max_08)
	{
		cout << max(min_08, min_10);
	}
	else
	{
		cout << -1;
	}

}

int main()
{
	fastio;
	solve();

	return 0;
}