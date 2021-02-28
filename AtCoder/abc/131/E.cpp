#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
	int n, k;
	cin >> n >> k;

	// 二部グラフの考えを使うけど二部グラフじゃない！
	if ( (n - 1) * (n - 2) / 2 >= k )
	{
		int m = (n - 1) * (n - 2) / 2;
		cout << n-1 + m-k << endl;
		for(int i = 2; i <= n; ++i)
		{
			cout << 1 << " " << i << endl;
		}

		for(int i = 2; i <= n - 1; ++i)
		{
			for(int j = i + 1; j <= n; ++j)
			{
				m--;
				if (m >= k) cout << i << " " << j << endl;
				else break;
			}
		}
		return;
	}
	cout << -1;
}

int main()
{
	fastio;
	solve();

	return 0;
}