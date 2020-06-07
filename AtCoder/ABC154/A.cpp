#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;


void solve()
{
	string s, t, u;
	int a, b;

	cin >> s >> t >> a >> b >> u;

	if (s == u)
	{
		a--;
	}
	else if (t ==  u)
	{
		b--;
	}

	cout << a << " " << b;
}

int main()
{
	fastio;
	solve();

	return 0;
}