#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

void solve()
{
	ll n;
	cin >> n;
	ll loop_cnt = 0;
	ll log = 1;
	while(n >= log)
	{
		n -= log;
		log *= 26;
		loop_cnt++;
	}

	for(int i = 0; i < loop_cnt; ++i)
	{
		log /= 26;
		cout << (char)(((n / log) % 26) + 'a');
	}
}

int main()
{
	fastio;
	solve();

	return 0;
}