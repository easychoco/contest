#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

// 最大公約数 : 3,4 ->  1
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

void solve()
{
	ll a, b;
	cin >> a >> b;

	map<ll, bool> cd;
	cd[1] = true;
	ll prime = 2;
	while(a >= prime * prime)
	{
		if (a % prime == 0)
		{
			while(a % prime == 0) a /= prime;
			cd[prime] = true;
		}
		prime++;
	}
	cd[a] = true;

	prime = 2;
	ll ans = 1;
	while(b >= prime * prime)
	{
		if (b % prime == 0)
		{
			while(b % prime == 0) b /= prime;
			if (cd.find(prime) != cd.end())
			{
				ans++;
			}
		}
		prime++;
	}
	if (b != 1 && cd.find(b) != cd.end())
	{
		ans++;
	}

	cout << ans;
}

int main()
{
	fastio;
	solve();

	return 0;
}