#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

void solve()
{
	ll a, r, n;
	cin >> a >> r >> n;

	if (r == 1)
	{
		cout << a;
		return;
	}

	while(n > 1)
	{
		if (a * r > 1000000000)
		{
			cout << "large";
			return;
		}
		a *= r;
		n--;
	}

	cout << a;	
}

int main()
{
	fastio;
	solve();

	return 0;
}