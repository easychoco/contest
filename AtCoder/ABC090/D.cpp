#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll = long long;

const double PI = 3.14159265358979;

void solve()
{
  ll n, k;
  cin >> n >> k;
  ll ans = 0;

  for(ll i = k + 1; i <= n; ++i)
  {
    // a % b >= k
    // a % i >= k
    ans += n / i * (i - k) + max(0LL, n % i - k + 1);
  }
  if (k == 0) ans -= n;
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}