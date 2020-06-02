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
	vector<int> x(n);
	int sum = 0;
	for(int i = 0; i < n; ++i)
	{
		cin >> x[i];
		sum += x[i];
	}
	int ave_dec = floor((double)sum / (double)n + 0.5);

	sum = 0;
	for(int i = 0; i < n; ++i)
	{
		sum += pow((x[i] - ave_dec), 2.0);
	}

	cout << sum;

}

int main()
{
	fastio;
	solve();

	return 0;
}