#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

const ll RANGE = 31622; // < sqrt(X) : sqrt(10^9) = 31622.8

int x;

constexpr ll mod5(const ll n)
{
	return (((((((n*n) % MOD) * n) % MOD)* n) % MOD)* n) % MOD;
}

bool calc(ll diff)
{
	if (diff > RANGE)
	{
		return false;
	}
	// a - b は x の約数
	// a - b = diff
	for(int a = 0; a < RANGE; ++a)
	{
		int b = a - diff;
		if(((mod5(a) - mod5(b)) + MOD) % MOD == x % MOD)
		{
			cout << a << " " << b << endl;
			return true;
		}
	}
	return false;
}

void solve()
{
	cin >> x;

	for (int i = 1; i * i <= x; i++)
	{
		if(x % i == 0)
		{
			if (calc(i)) return;
			if (calc(x / i)) return;
		}
	}

}

int main()
{
	fastio;
	solve();

	return 0;
}