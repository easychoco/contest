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
	vector<double> v(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	double value = v[0];
	for(int i = 1; i < n; ++i)
	{
		value = (value + v[i]) / 2.0;
	}
	printf("%.7f", value);
}

int main()
{
	fastio;
	solve();

	return 0;
}