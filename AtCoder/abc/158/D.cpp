#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

void solve()
{
	string s;
	cin >> s;

	int q;
	cin >> q;

	int t;
	bool reverse = false;

	deque<char> d;
	for(int i = 0; i < s.length(); ++i)
	{
		d.push_back(s[i]);
	}

	for(int i = 0; i < q; ++i)
	{
		cin >> t;
		if (t == 1)
		{
			reverse = !reverse;
		}
		else if (t == 2)
		{
			int f;
			char c;
			cin >> f >> c;
			if ((f - 1) == (int)reverse)
			{
				d.push_front(c);
			}
			else
			{
				d.push_back(c);
			}
		}
	}

	string ans = "";
	while(!d.empty())
	{
		ans += d.front();
		d.pop_front();
	}
	if (reverse)
	{
		std::reverse(ans.begin(), ans.end());
	}
	cout << ans;
}

int main()
{
	fastio;
	solve();

	return 0;
}