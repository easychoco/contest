#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
  int n, t_in, c, t;
  cin >> n >> t_in;
  int ans = 100000;
  for(int i = 0; i < n; ++i)
  {
    cin >> c >> t;
    if (t <= t_in) ans = min(ans, c);
  }
  if (ans == 100000) cout << "TLE";
  else cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}