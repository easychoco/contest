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
	cin >> n >> k;

	vector<int> h(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> h[i];
	}

	sort(h.begin(), h.end());

	ll sum = 0;
	for(int i = 0; i < n - k; ++i)
	{
		sum += h[i];
	}
	cout << sum;
}

int main()
{
	fastio;
	solve();

	return 0;
}