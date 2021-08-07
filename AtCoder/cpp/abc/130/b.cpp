#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
	int n, x, l;
	cin >> n >> x;
	int cnt = 1;
	int pos = 0;
	for(int i = 0; i < n; ++i)
	{
		cin >> l;
		pos = pos + l;
		if (x < pos) break;
		cnt++;
	}
	cout << cnt;
}

int main()
{
	fastio;
	solve();

	return 0;
}