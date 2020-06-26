#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;


void solve()
{
	int a, b;
	cin >> a >> b;
	if ((a + b) & 1)
	{
		cout << "IMPOSSIBLE";
	}
	else
	{
		cout << (a + b) / 2;
	}
}

int main()
{
	fastio;
	solve();

	return 0;
}