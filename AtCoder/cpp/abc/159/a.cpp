#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;


void solve()
{
	int n, m;
	cin >> n >> m;

	cout << (n * (n - 1) + m * (m - 1)) / 2 << endl;
}

int main()
{
	fastio;
	solve();

	return 0;
}