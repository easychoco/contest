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
  vector<ll> a(n);
  for(int i = 0; i < n; ++i)
  {
    cin >> a[i];
  }

  if (k == 0)
  {
    cout << *max_element(a.begin(), a.end());
    return;
  }

  auto f = [&](ll arg)
  {
    ll cnt = 0;
    for(int i = 0; i < n; ++i)
    {
      cnt += a[i] / arg;
      if (a[i] % arg == 0) cnt--;
    }
    return cnt <= k;
  };

  ll le = 0LL, re = 1000000001LL;
  while(re - le > 1)
  {
    ll mid = (le + re) / 2;
    if ( f(mid) ) re = mid;
    else le = mid;
  }

  cout << re;
}

int main()
{
  fastio;
  solve();

  return 0;
}