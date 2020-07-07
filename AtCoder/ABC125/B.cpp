#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
  int n;
  cin >> n;
  vector<int> v(n), c(n);
  for(int i = 0; i < n; ++i) cin >> v[i];
  for(int i = 0; i < n; ++i) cin >> c[i];

  int ans = 0;
  for(int i = 0; i < n; ++i)
  {
    ans += max(0, v[i] - c[i]);
  }
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}