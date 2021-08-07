#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;


void solve()
{
	int x, y;
	cin >> x >> y;
	cout << (((y <= x * 4) && ((y & 1) == 0) && (x * 2 <= y))  ? "Yes" : "No");
}

int main()
{
	fastio;
	solve();

	return 0;
}