#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
	int n, l;
	cin >> n >> l;
	int sum = n * (l - 1) + n * (n + 1) / 2;
	if (0 < l) sum -= l;
	if (l + n - 1 < 0) sum -= l + n - 1;
	cout << sum;
}

int main()
{
	fastio;
	solve();

	return 0;
}