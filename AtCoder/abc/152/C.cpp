#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

void solve()
{
	int n, p, min_p = 1e9, ans = 0;
	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		cin >> p;
		if (p < min_p)
		{
			++ans;
			min_p = p;
		}
	}

	cout << ans;
}

int main()
{
	fastio;
	solve();

	return 0;
}