#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n, m;
	cin >> n >> m;
	
	int sum = 0;
	for(int i = 0; i < m; ++i)
	{
		int a;
		cin >> a;
		sum += a;
	}
	cout << max(n - sum, -1) << endl;
}

int main()
{
	solve();

	return 0;
}
