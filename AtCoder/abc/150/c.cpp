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

	int ans_p = 0, ans_q = 0;

	vector<int> p(n);
	vector<int> q(n);
	vector<int> v(n);

	for(int i = 0; i < n; ++i)
	{
		v[i] = i + 1;
	}

	for(int i = 0; i < n; ++i)
	{
		cin >> p[i];
	}

	for(int i = 0; i < n; ++i)
	{
		cin >> q[i];
	}

	int loop_cnt = 0;
	do{
		loop_cnt++;
		if (v == p) { ans_p = loop_cnt; }
		if (v == q) { ans_q = loop_cnt; }
	} while(next_permutation(v.begin(), v.end()));

	cout << abs(ans_p - ans_q);
}

int main()
{
	fastio;
	solve();

	return 0;
}