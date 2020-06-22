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
	vector< vector<int> > a(n, vector<int>(n - 1));
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n - 1; ++j)
		{
			cin >> a.[i][j];
			a[i][j]--;
		}
	}

	int day = 0;
	while(true)
	{

	}


}

int main()
{
	fastio;
	solve();

	return 0;
}