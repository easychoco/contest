#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
	int a, b;
  cin >> a >> b;
  if (a <= 5) cout << 0;
  else if (a <= 12) cout << b / 2;
  else cout << b;
}

int main()
{
	fastio;
	solve();

	return 0;
}