#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

void solve()
{
	string s, t;
	cin >> s >> t;
	ll s_size = s.length();
	ll t_size = t.length();

	vector<int> bin[26] = {};
	for(int i = 0; i < s_size; ++i)
	{
		bin[ s[i] - 'a' ].emplace_back(i);
	}

	for(int i = 0; i < t_size; ++i)
	{
		if (bin[ t[i] - 'a' ].empty())
		{
			cout << "-1";
			return;
		}
	}

	vector<int> t_num(t_size, -1);
	
	t_num[0] = bin[ t[0] - 'a' ][0];
	for(int i = 1; i < t_size; ++i)
	{
		t_num[i] = bin[ t[i] - 'a' ][0];
		for(int j = 0; j < bin[ t[i] - 'a' ].size(); ++j)
		{
			if (bin[ t[i] - 'a' ][j] > t_num[i - 1])
			{
				t_num[i] = bin[ t[i] - 'a' ][j];
				break;
			}
		}
	}

	ll ans = 0;
	for(int i = 1; i < t_size; ++i)
	{
		if (t_num[i - 1] >= t_num[i])
		{
			ans += s_size;
		}
	}
	cout << ans + t_num.back() + 1;
}

int main()
{
	fastio;
	solve();

	return 0;
}