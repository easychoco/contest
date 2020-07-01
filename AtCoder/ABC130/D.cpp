#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);

	ll ans = 0, sum = 0;
	int le = 0, re = 1;
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
		if (sum < k)
		{
			sum += a[i];
			re = i;
		}
	}

	if (sum < k)
	{
		cout << 0;
		return;
	}

	while(re < n)
	{
		ans += n - re;
		sum -= a[le];
		le++;
		while(sum < k)
		{
			re++;
			sum += a[re];
		}
	}
	cout << ans;
}

int main()
{
	fastio;
	solve();

	return 0;
}