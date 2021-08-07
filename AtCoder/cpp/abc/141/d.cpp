#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

void solve()
{
	ll n, m, a , ans = 0;
	cin >> n >> m;
	priority_queue<ll> que;
	for(int i = 0; i < n; ++i)
	{
		cin >> a;
		que.push(a);
	}
	for(int i = 0; i < m; ++i)
	{
		a = que.top();
		que.pop();
		que.push(a / 2);
	}

	while(!que.empty())
	{
		ans += que.top();
		que.pop();
	}
	cout<< ans;
}

int main()
{
	fastio;
	solve();

	return 0;
}