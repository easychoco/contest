#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;


void solve()
{
	int n, k, m, a, sum = 0;
	cin >> n >> k >> m;
	for(int i = 0; i < n - 1; ++i)
	{
		cin >> a;
		sum += a;
	}

	int next_score = n * m - sum;
	cout << (next_score <= k ? max(0, next_score) : -1);
}

int main()
{
	fastio;
	solve();

	return 0;
}