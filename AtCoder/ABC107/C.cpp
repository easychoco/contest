#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
  ll n, k, x;
  cin >> n >> k;
  vector<ll> x_posi;
  vector<ll> x_nega;
  for(int i = 0; i < n; ++i)
  {
    cin >> x;
    (x < 0 ? x_nega : x_posi).emplace_back(x);
  }
  reverse(x_nega.begin(), x_nega.end());

  ll ans = 1LL << 60;
  int ps = x_posi.size();
  int ns = x_nega.size();
  for(int i = 0; i <= k; ++i)
  {
    int pi = i - 1;
    int ni = k - i - 1;
    if (ps <= pi) continue;
    if (ns <= ni) continue;

    ll cost = 0;
    if (ni < 0) cost = x_posi[pi]; 
    else if (pi < 0) cost = -x_nega[ni];
    else cost = min(x_posi[pi] * 2 - x_nega[ni], x_posi[pi] - x_nega[ni] * 2);

    ans = min(ans, cost);
  }
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}