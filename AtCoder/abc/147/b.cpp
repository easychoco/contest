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
	int ans = 0;
	int s_size = s.length();
	for(int i = 0; i < s_size / 2; ++i)
	{
		if (s[i] != s[s_size - i - 1])
		{
			ans++;
		}
	}
	cout << ans;
}

int main()
{
	fastio;
	solve();

	return 0;
}