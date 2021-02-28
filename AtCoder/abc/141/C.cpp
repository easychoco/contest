#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

void solve()
{
	int n, k, q;
	cin >> n >> k >> q;
	vector<int> a(n);

	if (k > q)
	{
		for(int i = 0; i < n; ++i) cout<< "Yes" << endl;
		return;
	}

	for(int i = 0; i < q; ++i)
	{
		int input;
		cin >> input; input--;
		a[input]++;
	}

	for(const auto& ia : a)
	{
		cout << (k - q + ia > 0  ? "Yes" : "No") << endl;
	}
}

int main()
{
	fastio;
	solve();

	return 0;
}