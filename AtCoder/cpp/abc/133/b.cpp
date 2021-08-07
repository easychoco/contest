#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
	int n, d;
	cin >> n >> d;
	vector< vector<int> > x(n, vector<int>(d));

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < d; ++j)
		{
			cin >> x[i][j];
		}
	}

	int ans = 0;
	for(int i = 0; i < n - 1; ++i)
	{
		for(int j = i + 1; j < n; ++j)
		{
			int sq_sum = 0;
			for(int k = 0; k < d; ++k)
			{
				int dif = x[i][k] - x[j][k];
				sq_sum += dif * dif;
			}
			if (fmod(abs(sqrt(sq_sum)), 1.0) <= 0.001)
			{
				ans++;
			}
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