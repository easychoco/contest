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
	string s;

	cin >> n >> s;

	int ans = 0;
	for(int i = 0; i < n - 2; ++i)
	{
		if (s.substr(i, 3) == "ABC")
		{
			ans++;
			i += 2;
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