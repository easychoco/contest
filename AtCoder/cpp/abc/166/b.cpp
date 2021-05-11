#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

void solve()
{
	int n, k;
	cin >> n >> k;
	vector<int> s(n, 0);

	for(int i = 0; i < k; ++i)
	{
		int d;
		cin >> d;
		for(int j = 0; j < d; ++j)
		{
			int a;
			cin >> a;
			s[a - 1] = 1;
		}
	}

	int ans = n;
	for(const auto& v : s)
	{
		ans -= v;
	}

	cout << ans << endl;


}

int main()
{
	fastio;
	solve();

	return 0;
}