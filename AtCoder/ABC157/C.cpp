#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

void solve()
{
	int n, m;
	cin >> n >> m;

	vector<int> ans(n, -1);
	for(int i = 0; i < m; ++i)
	{
		int s, c;
		cin >> s >> c;
		s--;

		if (c == 0 && s == 0 && n > 1)
		{
			cout << -1;
			return;
		}

		if (ans[s] == -1 || ans[s] == c)
		{
			ans[s] = c;
		}
		else
		{
			cout << -1;
			return;
		}
	}

	if (ans[0] == -1 && n > 1)
	{
		ans[0] = 1;
	}

	for(int i = 0; i < n; ++i)
	{
		cout << max(0, ans[i]);
	}

}

int main()
{
	fastio;
	solve();

	return 0;
}