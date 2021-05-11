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
	vector<int> l(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> l[i];
	}

	sort(l.begin(), l.end());
	
	ll ans = 0;
	for(int i = 0; i < n - 2; ++i)
	{
		for(int j = i + 1; j < n - 1; ++j)
		{
			vector<int>::iterator iter = lower_bound(l.begin(), l.end(), l[i] + l[j]);
			ll size = iter - l.begin();
			ans += size - j - 1;
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