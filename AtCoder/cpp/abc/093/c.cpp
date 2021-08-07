#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
  int a, b, c;
  cin >> a >> b >> c;

  int ans = 0;
  int m1 = min({a, b, c});
  int m3 = max({a, b, c});
  int m2 = a + b + c - (m1 + m3);

  // m1 <= m2 <= m3
  if ((m1 & 1) == (m2 & 1))
  {
    ans = (m2 - m1) / 2;
    ans += m3 - m2;
  }
  else if ((m1 & 1) == (m3 & 1))
  {
    ans = (m3 - m1) / 2;
    ans += (m3 - m2) / 2 + 2;
  }
  else if ((m2 & 1) == (m3 & 1))
  {
    ans = (m3 - m2) / 2;
    ans += (m3 - m1) / 2  + 2;
  }
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}