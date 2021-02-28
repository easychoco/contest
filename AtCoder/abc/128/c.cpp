#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
	int n, m, k_size, s;
	cin >> n >> m;
	vector< vector<int> > k(m, vector<int>());
	vector<int> p(m);
	for(int i = 0; i < m; ++i)
	{
		cin >> k_size;
		for(int j = 0; j < k_size; ++j)
		{
			cin >> s;
			s--;
			k[i].emplace_back(s);
		}
	}
	for(int i = 0; i < m; ++i)
	{
		cin >> p[i];
	}

	int ans = 0;
	int mask = 1 << n;
	while(mask--, mask >= 0)
	{
		vector<int> sw(m, 0);
		for(int i = 0; i < m; ++i)
		{
			for(const auto& j : k[i])
			{
				sw[i] ^= ((mask & (1 << j)) > 0);
			}
		}
		if (sw == p) ans++;
	}
	cout << ans;
}

int main()
{
	fastio;
	solve();

	return 0;
}