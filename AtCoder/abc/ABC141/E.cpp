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
	string s;
	cin >> n >> s;

	int ans = 0;
	for(int a = 0; a < n; ++a)
	{
		vector<int> Z(n - a);
		Z[0] = n - a;
		int i = 1, j = 0;
		while(a + i < n)
		{
			while(a + i + j < n && s[a + j] == s[a + i + j])
			{
				j++;
			}
			Z[i] = j;
			ans = max(ans, min(i, Z[i]));

			if(j == 0)
			{
				i++;
				continue;
			}

			int k = 1;
			while(k < j && k + Z[k] < j)
			{
				Z[i + k] = Z[k];
				ans = max(ans, min(i + k, Z[i + k]));
				k++;
			}
			i += k;
			j -= k;
		}
	}
	cout << ans;
}

int main()
{
	fastio;
	solve();

	return 0;
}