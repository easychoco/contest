#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

struct Magic
{
	int a, b;

	bool operator>(const Magic& another) const {
		return a  > another.a;
	}
};


void solve()
{
	int h, n, a, b;
	cin >> h >> n;
	vector< Magic > magic(n);

	for(int i = 0; i < n; ++i)
	{
		cin >> magic[i].a >> magic[i].b;
	}

	sort(magic.begin(), magic.end(), greater<Magic>());

	// モンスターの体力を i 減らすため消耗する魔力の最小値
	vector<int> dp(h + magic[0].a + 1, 1e9);
	dp[0] = 0;

	for(int i = magic[magic.size() - 1].a; i <= h + magic[0].a; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			if (0 <= i - magic[j].a)
			{
				dp[i] = min(dp[i], dp[i - magic[j].a] + magic[j].b);
			}
		}
	}

	int ans = 1e9;
	for(int i = h; i <= h + magic[0].a; ++i)
	{
		ans = min(ans, dp[i]);
	}
	cout << ans;
}

int main()
{
	fastio;
	solve();

	return 0;
}