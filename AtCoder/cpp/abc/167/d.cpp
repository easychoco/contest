#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

void solve()
{
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	vector<ll> b(n, 0);

	for(ll i = 0; i < n; ++i)
	{
		ll in;
		cin >> in;
		a[i] = in - 1;
	}

	if (a[0] == 0)
	{
		cout << 1 << endl;
		return;
	}

	// 循環を見つけて mod
	ll now = 0;
	ll loop_cnt = 1;
	ll loop_start_cnt = 0;
	bool conti = true;
	b[0] = 1;

	while(conti)
	{
		loop_cnt++;
		now = a[now];
		if (b[now] > 0)
		{
			conti = false;
			loop_start_cnt = b[now];
			break;
		}

		b[now] = loop_cnt;
	}

	ll dest = 1;
	dest = (k - loop_start_cnt + 1) % (loop_cnt - loop_start_cnt);

	ll ans = 0;
	for(ll i = 0; i < min(k, loop_start_cnt + dest - 1); ++i)
	{
		ans = a[ans];
	}
	cout << ans + 1 << endl;
}

int main()
{
	fastio;
	solve();

	return 0;
}