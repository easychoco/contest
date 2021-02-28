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

	int c[9][9];

	for(int i = 0; i < 9; ++i)
	for(int j = 0; j < 9; ++j)
	c[i][j] = 0;

	for(int i = 1; i <= n; ++i)
	{
		if (i % 10 == 0)
		{
			continue;
		}
		string s = to_string(i);
		c[s.front() - '0' - 1][s.back() - '0' - 1]++;
	}

	int ans = 0;
	for(int i = 0; i < 9; ++i)
	for(int j = 0; j < 9; ++j)
	ans += c[i][j] * c[j][i];

	cout << ans;
}

int main()
{
	fastio;
	solve();

	return 0;
}