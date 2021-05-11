#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
	string s;
	cin >> s;
	
	ll dp[100005][13];
	for(int i = 0; i < 13; ++i) dp[0][i] = 0;
	dp[0][0] = 1;

	int len = s.length();
	for(int i = 0; i < len; ++i)
	{
		for(int j = 0; j < 13; ++j) dp[i + 1][j] = 0;

		int num = ((s[i] == '?') ? -1 : s[i] - '0');
		for(int j = 0; j < 10; ++j)
		{
			// num が数字の時はその数のみ、? のときは0~9について計算
			if (num != -1 && num != j) continue;
			for(int k = 0; k < 13; ++k)
			{
				dp[i + 1][(k * 10 + j) % 13] += dp[i][k];
			}
		}
		for (int j = 0; j < 13; ++j)
		{
			dp[i + 1][j] %= MOD;
		}
	}
	cout << dp[len][5];
}

int main()
{
	fastio;
	solve();

	return 0;
}