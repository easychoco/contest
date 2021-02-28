#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;


void solve()
{
	int n, m;
	cin >> n >> m;

	vector<int> a(n);
	int all_sum = 0;
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
		all_sum += a[i];
	}
	
	sort(a.begin(), a.end(), greater<int>());
	cout << ((all_sum / (4.0 * m) <= a[m - 1]) ? "Yes" : "No") << endl;
}

int main()
{
	fastio;
	solve();

	return 0;
}


