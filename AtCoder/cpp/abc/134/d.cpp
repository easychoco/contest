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
	vector<int> a(n + 1, 0);
	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	// 1は考えなくていい
	// 半分以降は決まり：倍数が1つだけ
	// 前半の半分について考える
	bitset<200000 + 1> ball;
	for(int i = n / 2 + 1; i <= n; ++i)
	{
		ball[i] = a[i];
	}

	for(int i = n / 2; i >= 1; --i)
	{
		int next_b = a[i];
		for(int j = i * 2; j <= n; j += i)
		{
			next_b ^= ball[j];
		}
		ball[i] = next_b;
	}

	cout << ball.count() << endl;
	for(int i = 1; i <= n; ++i)
	{
		if (ball[i]) cout << i << " ";
	}
}

int main()
{
	fastio;
	solve();

	return 0;
}