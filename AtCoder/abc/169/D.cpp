#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

// 素数判定
// から派生して、最初の約数を返す
int nextPrime(ll a)
{
    if (a == 1) return 1;
    for (ll i = 2; i * i <= a; i++)
	{
        if(a % i == 0) return i;
    }
    return -1;
}

void solve()
{
	ll n;
	cin >> n;

	ll first_prime = nextPrime(n);
	if (first_prime <= 0)
	{
		cout << 1;
		return;
	}
	if (first_prime == 1)
	{
		cout << 0;
		return;
	}

	map<ll, ll> mp;

	int ans = 0;
	for (int i = first_prime; i <= n; i = nextPrime(n)) 
	{
		if (i == 1) // nが割り切れた
		{
			break;
		}
		if (i == -1) // nが素数の時も割り切れた
		{
			mp[n]++;
			break;
		}
		while (n % i == 0)
		{
			mp[i]++;
			n /= i;
		}
	}

	// mp内には素因数分解
	for(auto& m : mp)
	{
		int i = 1;
		while(m.second >= i)
		{
			// n*(n+1)/2 
			m.second -= i;
			++i;
			++ans;
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