#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

void solve()
{
	int low_digit = 0;
	int high_digit = 0;
	int log10 = 1;
	int mod = 10;

	int perm[6] = { 0, 2, 22, 222, 2222, 22222 };
	int ans[200003] = { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, };

	for(int i = 10; i <= 200000; ++i)
	{
		if      (i >= 100000) { log10 = 5; mod = 100000; }
		else if (i >= 10000)  { log10 = 4; mod = 10000; }
		else if (i >= 1000)   { log10 = 3; mod = 1000; }
		else if (i >= 100)    { log10 = 2; mod = 100; }
		else                  { log10 = 1; mod = 10; }
		
		low_digit = i % 10;
		high_digit = i / mod;

		if (low_digit == 0)
		{
			ans[i] = 0;
			continue;
		}
		if (high_digit > low_digit)
		{
			ans[i] = perm[log10];
		}
		else if (high_digit < low_digit)
		{
			ans[i] = perm[log10 - 1];
		}
		else // low_digit == high_digit
		{
			ans[i] = perm[log10 - 1] + ( (i / 10) % (mod / 10) ) * 2 + 3;
		}
	}

	int n;
	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		ans[i + 1] = ans[i] + ans[i + 1];
	}

	cout << ans[n];
}

int main()
{
	fastio;
	solve();

	return 0;
}