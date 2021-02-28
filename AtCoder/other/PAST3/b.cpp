#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;


void solve()
{
	int n, m, q;
	cin >> n >> m >> q;

	vector< vector<int> > solver(n, vector<int>(0));
	vector< vector<int> > problem(n, vector<int>(0));	

	int s;
	for(int i = 0; i < q; ++i)
	{
		cin >> s;
		if (s == 1)
		{
			int s;
			cin >> s;
			s--;

			int ans = 0;
			for(auto& v : solver[s])
			{
				ans += n - problem[v].size();
			}
			cout << ans << endl;
		}
		else
		{
			int s, p;
			cin >> s >> p;
			s--;
			p--;
			solver[s].emplace_back(p);
			problem[p].emplace_back(s);
		}
		
	}
}

int main()
{
	fastio;
	solve();

	return 0;
}