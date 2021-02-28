#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

void solve()
{
	int x, n;
	cin >> x >> n;
	vector<bool> p(105, true);
	int input;
	for(int i = 0; i < n; ++i)
	{
		cin >> input;
		p[input] = false;
	}

	if (p[x])
	{
		cout << x;
		return;
	}

	for(int i = 1; i < 100; ++i)
	{
		if (x - i < 0 || p[x - i])
		{
			cout << x - i;
			return;
		}
		if (x + i > 100 || p[x + i])
		{
			cout << x + i;
			return;
		}
	}
}

int main()
{
	fastio;
	solve();

	return 0;
}