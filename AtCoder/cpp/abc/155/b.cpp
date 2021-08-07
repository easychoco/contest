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

	int a;
	bool ans = true;
	for(int i = 0; i < n; ++i)
	{
		cin >> a;
		ans = ans & ((a & 1) | (a % 3 == 0) | (a % 5 == 0));
	}

	cout << (ans ? "APPROVED" : "DENIED");

}

int main()
{
	fastio;
	solve();

	return 0;
}