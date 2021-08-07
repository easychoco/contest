#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

void solve()
{
	int n, x, y;
	cin >> n >> x >> y;
	vector<int> bin(n, 0);

	for(int i = 1; i <= n - 1; ++i)
	{
		for(int j = i + 1; j <= n; ++j)
		{
			int w_straight = j - i;

			int w_curve = min( (abs(i - x) + abs(j - y) + 1),
							 (abs(i - y) + abs(j - x) + 1) );

			bin[ min(w_straight, w_curve) ]++;
		}
	}

	for(int i = 1; i < n; ++i)
	{
		cout << bin[i] << endl;
	}
}

int main()
{
	fastio;
	solve();

	return 0;
}