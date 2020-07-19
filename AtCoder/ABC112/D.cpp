#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
  ll n, m;
  cin >> n >> m;

  ll ans = 1;
  for(ll i = 1; i * i <= m; ++i)
  {
    if (m % i == 0)
    {
      if (i * n <= m) ans = max(ans, i);
      if (m / i * n <= m) ans = max(ans, m / i);
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