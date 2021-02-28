#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;
constexpr int INF = 1 << 30;

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	reverse(a.begin(), a.end());

	vector<int> dp(n, INF);
	for(int i = 0; i < n; ++i)
	{
		*upper_bound(dp.begin(), dp.end(), a[i]) = a[i];
	}

	cout << lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
}

int main()
{
	fastio;
	solve();

	return 0;
}