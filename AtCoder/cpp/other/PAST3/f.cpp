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

	string ans = "";
	string mid = "";
	vector< set<char> > bin(n, set<char>());

	string s;
	for(int i = 0; i < n / 2; ++i)
	{
		cin >> s;
		for(int j = 0; j < s.length(); ++j)
		{
			bin[i].insert(s[j]);
		}
	}

	if (n & 1)
	{
		cin >> s;
		mid = s[0];
	}

	for(int i = n / 2 - 1; i >= 0; --i)
	{
		cin >> s;
		bool ret = true;
		for(int j = 0; j < s.length(); ++j)
		{
			auto itr = bin[i].find(s[j]);
			if (itr != bin[i].end())
			{
				ans = *itr + ans;
				ret = false;
				break;
			}
		}
		if (ret)
		{
			cout << -1;
			return;
		}
	}
	cout << ans;
	cout << mid;
	reverse(ans.begin(), ans.end());
	cout << ans;
}

int main()
{
	fastio;
	solve();

	return 0;
}