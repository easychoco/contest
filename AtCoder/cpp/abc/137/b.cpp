#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;


void solve()
{
	int k, x;
	cin >> k >> x;
	for(int i = x - k + 1; i < x + k; ++i)
	{
		cout << i << " ";
	}
}

int main()
{
	fastio;
	solve();

	return 0;
}