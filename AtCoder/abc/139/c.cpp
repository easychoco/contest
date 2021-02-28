#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

void solve()
{
	int n, ans = 0, score = 0;
	cin >> n;
	vector<int> h(n);
	cin >> h[0];
	for(int i = 1; i < n; ++i)
	{
		cin >> h[i];
		if (h[i - 1] >= h[i])
		{
			score++;
		}
		else
		{
			ans = max(ans, score);
			score = 0;
		}
	}
	ans = max(ans, score);

	cout << ans;
}

int main()
{
	fastio;
	solve();

	return 0;
}