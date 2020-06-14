#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

void solve()
{
	const ll MAX_SIZE = 1000005;

	bool num[MAX_SIZE];
	for(int i = 0; i < MAX_SIZE; ++i)
	{
		num[i] = false;
	}

	int n;
	cin >> n;
	vector<ll> a(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end());

	int ans = 0;
	for(int i = 0; i < n; ++i)
	{
		if(num[a[i]] == true)
		{
			continue;
		}

		// 重複がなければ
		if (!(i < n - 1 && a[i] == a[i + 1]))
		{
			ans++;
		}

		ll prime = 0;
		while(prime += a[i], prime < MAX_SIZE)
		{
			num[prime] = true;
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