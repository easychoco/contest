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
	vector<int> p(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> p[i];
	}

	ll ans = 0;
	for(int w = 2; w <= n; ++i)
	{
		ll max1 = 0;
		ll max2 = 0;
		for(int i = 2; i < w; ++i)
		{
			if (max1 < p[i])
			{
				max1 = p[i];
				max2 = max1;
			}
			else if (max2 < p[i])
			{
				max2 = p[i];
			}
		}

		for(int i = 0; i + w < n; ++i)
		{
			
		}
	}
}

int main()
{
	fastio;
	solve();

	return 0;
}