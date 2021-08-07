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
	int ans[200003] = { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, };

	for(int i = 10; i <= 99; ++i)
	{
		low_digit = i % 10;
		high_digit = i / 10;
		if (low_digit == 0)
		{
			ans[i] = 0;
		}
		else if (high_digit > low_digit)
		{
			ans[i] = 2;
		}
		else if (high_digit < low_digit)
		{
			ans[i] = 0;
		}
		else // low_digit == high_digit
		{
			ans[i] = 3;
		}
	}
	for(int i = 100; i <= 999; ++i)
	{
		low_digit = i % 10;
		high_digit = i / 100;
		if (low_digit == 0)
		{
			ans[i] = 0;
		}
		else if (high_digit > low_digit)
		{
			ans[i] = 22;
		}
		else if (high_digit < low_digit)
		{
			ans[i] = 2;
		}
		else // low_digit == high_digit
		{
			ans[i] = 5 + ((i / 10) % 10) * 2;
		}
	}
	for(int i = 1000; i <= 9999; ++i)
	{
		low_digit = i % 10;
		high_digit = i / 1000;
		if (low_digit == 0)
		{
			ans[i] = 0;
		}
		else if (high_digit > low_digit)
		{
			ans[i] = 222;
		}
		else if (high_digit < low_digit)
		{
			ans[i] = 22;
		}
		else // low_digit == high_digit
		{
			ans[i] = 25 + ((i / 10) % 100) * 2;
		}	
	}
	for(int i = 10000; i <= 99999; ++i)
	{
		low_digit = i % 10;
		high_digit = i / 10000;
		if (low_digit == 0)
		{
			ans[i] = 0;
		}
		else if (high_digit > low_digit)
		{
			ans[i] = 2222;
		}
		else if (high_digit < low_digit)
		{
			ans[i] = 222;
		}
		else // low_digit == high_digit
		{
			ans[i] = 225 + ((i / 10) % 1000) * 2;
		}	
	}
	for(int i = 100000; i <= 200000; ++i)
	{
		low_digit = i % 10;
		high_digit = i / 100000;
		if (low_digit == 0)
		{
			ans[i] = 0;
		}
		else if (high_digit > low_digit)
		{
			cout << "naihazu " << i << endl;
		}
		else if (high_digit < low_digit)
		{
			ans[i] = 2222;
		}
		else // low_digit == high_digit
		{
			ans[i] = 2225 + ((i / 10) % 10000) * 2;
		}	
	}

	int n;
	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		ans[i + 1] = ans[i] + ans[i + 1];
		// cout << i + 1 << " " << ans[i + 1] << endl;
	}

	cout << ans[n];


}

int main()
{
	fastio;
	solve();

	return 0;
}