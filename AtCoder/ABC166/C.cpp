#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

void solve()
{
	int n, m;
	cin >> n >> m;

	vector<int> h(n);
	vector<bool> isGood(n, true);

	for(int i = 0; i < n; ++i)
	{
		cin >> h[i];
	}
	for(int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;

		isGood[a] = isGood[a] & ( h[b] < h[a] );
		isGood[b] = isGood[b] & ( h[a] < h[b] );
	}

	int ans = 0;
	for(int i = 0; i < n; ++i)
	{
		if( isGood[i] )
		{
			ans++;
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