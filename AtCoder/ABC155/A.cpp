#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;


void solve()
{
	int a, b, c;
	cin >> a >> b >> c;

	if (a != b && b != c && a != c)
	{
		cout << "No";
	}
	else if (a == b && b == c && a == c)
	{
		cout << "No";
	}
	else
	{
		cout << "Yes";
	}
	
	
}

int main()
{
	fastio;
	solve();

	return 0;
}