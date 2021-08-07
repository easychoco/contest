#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

void solve()
{
	string s;
	cin >> s;

	int k;
	cin >> k;

	// 桁数
   int log = s.size();

	// dp0[i][j] : 上からi桁まで決めて、0でない桁がj個あり、Nより小さいことが確定している
	// dp1[i][j] : 上からi桁まで決めて、0でない桁がj個あり、Nより小さいことが確定していない
    vector< vector<ll> > dp0(log + 1, vector<ll>(k + 1, 0));
    vector< vector<ll> > dp1(log + 1, vector<ll>(k + 1, 0));

    dp0[0][0]=1;
    dp1[1][1]=1;
	
	for(int i = 0; i < log; ++i)
	{
		int num = s[i] - '0';

		for(int j = 0; j <= k; ++j)
		{
			if (num == 0)
			{
				dp0[i + 1][j] += dp0[i][j];
				if (j + 1 <= k)
				{
					dp0[i + 1][j + 1] += dp0[i][j] * 9;
				}
				if (j != 0)
				{
					dp1[i + 1][j] += dp1[i][j];
				}
			}
			else
			{
				dp0[i + 1][j] += dp0[i][j] + dp1[i][j];
				if(i == 0 && j == 0)
				{
					dp0[i + 1][j + 1] += dp0[i][j] * (num - 1);
				}
				else if (j + 1 <= k)
				{
					dp0[i + 1][j + 1] += dp0[i][j] * 9 + dp1[i][j] * (num - 1);
				}
				if(j != 0 && j + 1 <= k)
				{
					dp1[i + 1][j + 1] += dp1[i][j];
				}
			}
		}
	}

	cout << dp0[log][k] + dp1[log][k];

	/*
	
	// 上から k桁の数字
	int top_num = stoi(s.substr(0, k));

	ll ans = 0;

	// 最大位数が0の時
	// (log-1) C k が9通り
	ans += pow(9, k) * comb(log - 1, k);

	cout << ans << endl;

	// 最大位数が0でないとき

	if (k == 1)
	{
		ans += top_num;
	}
	else if (k == 2)
	{
		ans += (top_num / 10 - 1) * 9 * (log - 1);
		cout << ans << endl;

		ans += (top_num % 10) * 9 * (log - 2);
		cout << ans << endl;

		ans += (log == k) ? (top_num % 10) : 1;
	}
	else if (k == 3)
	{
		ans += (top_num / 100 - 1) * 9 * (log - 1);
		cout << ans << endl;

		ans += ((top_num % 100) / 10) * 9 * (log - 2);
		cout << ans << endl;

		ans += (log == k) ? ((top_num % 10) / 10) : 1;
	}
	else while(true) cout << "nanikaokashii";
	cout << ans;
	*/
}

int main()
{
	fastio;
	solve();

	return 0;
}