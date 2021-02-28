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
	unordered_map< string, ll > ana_list;

	string s;
	for(int i = 0; i < n; ++i)
	{
		cin >> s;
		sort(s.begin(), s.end());
		ana_list[s]++;
	}

	ll ans = 0;
	for(const auto& ana : ana_list)
	{
		ans += ana.second * (ana.second - 1LL) / 2LL;
	}
	cout << ans;
}

int main()
{
	fastio;
	solve();

	return 0;
}