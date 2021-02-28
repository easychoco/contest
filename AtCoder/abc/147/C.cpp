#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

using Pair = pair<int, int>;
#define X first
#define Y second

void solve()
{
	int n;
	cin >> n;

	vector< vector<Pair> > saying(n, vector<Pair>());

	int a, x, y;
	for(int i = 0; i < n; ++i)
	{
		cin >> a;
		for(int j = 0; j < a; ++j)
		{
			cin >> x >> y;
			x--;
			saying[i].emplace_back(make_pair(x, y));
		}
	}

	int people = 1 << n; // bit 0で不親切, 1で正直者
	int ans = 0;
	while(people -= 1, people >= 0)
	{
		bitset<15> mask(people);
		if ((int)mask.count() <= ans) continue;

		bool ok = true;
		for(int i = 0; i < n; ++i)
		{
			if (mask[i])
			{
				for(const auto& s : saying[i])
				{
					ok &= ((int)mask[s.X] == s.Y);
				}
				if (!ok) break;
			}
		}
		if (ok)
		{
			ans = (int)mask.count();
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