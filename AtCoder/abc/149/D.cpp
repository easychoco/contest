#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

void solve()
{
	int n, k, r, s, p;
	cin >> n >> k >> r >> s >> p;
	string t;
	cin >> t;

	int ans = 0;
	for(int i = 0; i < k; ++i)
	{
		if (t[i] == 'r')
		{
			ans += p;
		}
		if (t[i] == 's')
		{
			ans += r;
		}
		if (t[i] == 'p')
		{
			ans += s;
		}
	}
	for(int i = k; i < n; ++i)
	{
		if (t[i] == 'r')
		{
			if (t[i - k] != 'r') ans += p;
			if (t[i - k] == 'r') t[i] = 'o';
		}
		if (t[i] == 's')
		{
			if (t[i - k] != 's') ans += r;
			if (t[i - k] == 's') t[i] = 'o';
		}
		if (t[i] == 'p')
		{
			if (t[i - k] != 'p') ans += s;
			if (t[i - k] == 'p') t[i] = 'o';

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