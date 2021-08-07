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

	unordered_map<string, int> ans;
	ans["SUN"] = 7;
	ans["MON"] = 6;
	ans["TUE"] = 5;
	ans["WED"] = 4;
	ans["THU"] = 3;
	ans["FRI"] = 2;
	ans["SAT"] = 1;

	cout << ans[s];
}

int main()
{
	fastio;
	solve();

	return 0;
}