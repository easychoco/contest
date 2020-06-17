#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

void solve()
{
	int n;
	cin >> n;

	for(int i = 1; i <= 9; ++i)
	{
		if (n % i == 0 && n / i <= 9)
		{
			cout << "Yes";
			return;
		}
	}
	cout << "No";
}

int main()
{
	fastio;
	solve();

	return 0;
}