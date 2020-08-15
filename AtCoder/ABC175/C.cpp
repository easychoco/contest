#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
  ll x, k, d;
  cin >> x >> k >> d;
  x = abs(x);

  if (1e17 / d < k || x < k * d)
  {
    ll num = x / d;
    if (num % 2 == k % 2)
    {
      cout << x - num * d;
    }
    else
    {
      cout << -(x - num * d - d);
    }
    
  }
  else // (x > k * d)
  {
    cout << x - k * d;
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}