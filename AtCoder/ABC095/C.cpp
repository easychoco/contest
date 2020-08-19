// #include <bits/stdc++.h>
#include <iostream>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  
  int ans = a * x + b * y;
  ans = min( ans, c * 2 * max(x, y) );

  if (x < y)
  {
    ans = min( ans, x * 2 * c + (y - x) * b );
  }
  else
  {
    ans = min( ans, y * 2 * c + (x - y) * a );
  }
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}