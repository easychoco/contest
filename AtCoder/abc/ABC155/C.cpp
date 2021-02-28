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

	map<string, int> mp;
	string s;

	int max_cnt = 0;
	for(int i = 0; i < n; ++i)
	{
		cin >> s;
		mp[s]++;
		max_cnt = max(max_cnt, mp[s]);
	}

	for(auto& m : mp)
	{
		if (m.second == max_cnt)
		{
			cout << m.first << endl;
		}
	}
}

int main()
{
	fastio;
	solve();

	return 0;
}