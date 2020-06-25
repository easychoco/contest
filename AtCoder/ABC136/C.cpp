#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

void solve()
{
	int n, h;
	cin >> n;
	int post_h = 0;
	for(int i = 0; i < n; ++i)
	{
		cin >> h;
		if (post_h > h)
		{
			cout << "No";
			return;
		}
		post_h = max(post_h, h - 1);
	}
	cout << "Yes";
}

int main()
{
	fastio;
	solve();

	return 0;
}