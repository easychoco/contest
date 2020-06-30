#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
	ll n, a, b;
	cin >> n;
	vector<P> task(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> a >> b;
		task[i] = P(b, a);
	}
	sort(task.begin(), task.end());

	ll sum_a = 0, now_b = 0;
	for(int i = 0; i < n; ++i)
	{
		now_b = task[i].first;
		sum_a += task[i].second;
		if (now_b < sum_a)
		{
			cout << "No";
			return;
		}
	}
	cout << "Yes";
}

int main()
{
	fastio;
	solve();

	return 0;
}