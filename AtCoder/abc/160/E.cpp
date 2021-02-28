#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

void solve()
{
	int x, y, a, b, c;
	cin >> x >> y >> a >> b >> c;
	priority_queue<ll> r;
	priority_queue<ll> g;
	priority_queue<ll> non;

	for(int i = 0; i < a; ++i)
	{
		ll in;
		cin >> in;
		r.push(in);
	}
	for(int i = 0; i < b; ++i)
	{
		ll in;
		cin >> in;
		g.push(in);
	}
	for(int i = 0; i < c; ++i)
	{
		ll in;
		cin >> in;
		non.push(in);
	}

	ll ans = 0;
	int non_cnt = 0;
	while(x + y - non_cnt > 0)
	{
		ll next_r   = (x <= 0 || r.empty()) ? 0 : r.top();
		ll next_g   = (y <= 0 || g.empty()) ? 0 : g.top();
		ll next_non = non.empty() ? 0 : non.top();

		if (next_r >= next_g && next_r >= next_non)
		{
			x--;
			ans += next_r;
			r.pop();
		}
		else if (next_g >= next_r && next_g >= next_non)
		{
			y--;
			ans += next_g;
			g.pop();
		}
		else if (next_non >= next_g && next_non >= next_r)
		{
			non_cnt++;
			ans += next_non;
			non.pop();
		}
		else
		{
			cout << "nazo" << endl;
		}
	}
	cout << ans <<  endl;

}

int main()
{
	fastio;
	solve();

	return 0;
}