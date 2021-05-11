#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

ll f(ll n)
{ 
  if (n == 1) return 1;
  return ((n * f(n - 1)) % MOD);
}

void solve()
{
  int n, m;
  cin >> n >> m;
  if (abs(n - m) > 1)
  {
    cout << 0;
    return;
  }
  
  ll ans = 1 + (n == m);
  ans *= f(n);
  ans %= MOD;
  ans *= f(m);
  ans %= MOD;
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}
