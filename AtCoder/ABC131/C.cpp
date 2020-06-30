#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

// 最大公約数 : 3,4 ->  1
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

// 最小公倍数 : 3,4 -> 12
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

// a 以上 b 以下の数のうち c で割り切れるものの個数
ll ranged_div_num(ll a, ll b, ll c)
{
	return (b / c - (a-1) / c);
}

void solve()
{
	ll a, b, c, d;
	cin >> a >> b >> c >> d;

	ll all = b - a + 1;
	cout << all - ( ranged_div_num(a, b, c) + ranged_div_num(a, b, d) - ranged_div_num( a, b, lcm(c, d) ) );
}

int main()
{
	fastio;
	solve();

	return 0;
}