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
	vector<int> a(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	int max1 = 0;
	int max2 = 1;
	for(int i = 1; i < n; ++i)
	{
		if (a[max1] < a[i])
		{
			max2 = max1;
			max1 = i;
		}
		else if (a[max2] < a[i])
		{
			max2 = i;
		}
	}
	for(int i = 0; i < n; ++i)
	{
		cout << (i == max1 ? a[max2] : a[max1]) << endl;
	}
}

int main()
{
	fastio;
	solve();

	return 0;
}