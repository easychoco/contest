#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
using namespace std;

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n + 1);

	for(int i = 1; i < n; ++i)
	{
		int in;
		cin >> in;
		a[in]++;
	}

	for(int i = 1; i <= n; ++i)
	{
		cout << a[i] << "\n";
	}
}

int main()
{
	fastio;
	solve();

	return 0;
}
