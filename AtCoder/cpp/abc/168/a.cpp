#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;


void solve()
{
	int a;
	cin >> a;

	int b = a % 10;
	string ans = "";
	if (b == 3)
	{
		ans = "bon";
	}
	else if(b == 0 || b == 1 || b == 6 || b == 8)
	{
		ans = "pon";
	}
	else{
		ans = "hon";
	}
	cout << ans << endl;
}

int main()
{
	fastio;
	solve();

	return 0;
}