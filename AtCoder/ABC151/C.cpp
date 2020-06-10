#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

void solve()
{
	int n, m, p;
	string s;
	cin >> n >> m;

	vector<int> problems(n, -1);
	for(int i = 0; i < m; ++i)
	{
		cin >> p >> s;
		p--;
		if (problems[p] <= 0)
		{
			if (s == "WA")
			{
				problems[p]--;
			}
			else if(s == "AC")
			{
				problems[p] *= -1;
			}
		}
	}

	int ans_ac = 0;
	int ans_wa = 0;
	for(const auto& v : problems)
	{
		if (v > 0)
		{
			++ans_ac;
			ans_wa += v - 1;
		}
	}

	cout << ans_ac << " " << ans_wa;
}

int main()
{
	fastio;
	solve();

	return 0;
}