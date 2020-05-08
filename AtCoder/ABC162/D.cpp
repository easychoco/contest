#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

int toIndex(char c)
{
	if (c == 'R')return 0;
	if (c == 'G')return 1;
	if (c == 'B')return 2;

	//cout << "nazo : " << c << endl;
	return 0;
}

void solve()
{
	int n;
	string s;
	cin >> n >> s;

	ll ans = 0;

	{
		ll cnt[3] = { 0, 0, 0 };
		for(const auto& c : s)
		{
			cnt[toIndex(c)]++;
		}
		ans = cnt[0] * cnt[1] * cnt[2];
	}

	for(int diff = 1; diff <= n / 2; ++diff)
	{
		for(int i = 0; i <= n - 1 - diff * 2; ++i)
		{
			int j = i + diff;
			int k = j + diff;
			if(s[i] != s[j] && s[i] != s[k] && s[j] != s[k])
			{
				ans--;
			}
		}
	}

	cout << ans << endl;
}

int main()
{
	fastio;
	solve();

	return 0;
}