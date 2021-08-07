#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

void solve()
{
	int n, k;
	string s;
	cin >> n >> k >> s;

	deque<int> now = { 1 };
	for(int i = 1; i < n; ++i)
	{
		if (s[i - 1] == s[i]) now.back()++;
		else now.push_back(1);
	}

	while(k--)
	{
		if (now.size() == 1) break;
		if (now.size() == 2)
		{
			int v = now.front() + now.back();
			now.pop_front();
			now.pop_front();
			now.push_front(v);
			break;
		}

		int val = 0;
		val += now.front(); now.pop_front();
		val += now.front(); now.pop_front();
		val += now.front(); now.pop_front();
		now.push_front(val);
	}

	int ans = 0;
	while(!now.empty())
	{
		ans += now.front() - 1;
		now.pop_front();		
	}
	cout << ans;
}

int main()
{
	fastio;
	solve();

	return 0;
}