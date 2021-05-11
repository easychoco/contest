#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
  ll n, k;
  cin >> n >> k;
  vector<ll> h(n);
  for(int i = 0; i < n; ++i)
  {
    cin >> h[i];
  }

  sort(h.begin(), h.end());
  ll ans = 1LL << 60;
  for(int i = 0; i <= n - k; ++i)
  {
    ans = min(ans, h[i + k - 1] - h[i]);
  }
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}