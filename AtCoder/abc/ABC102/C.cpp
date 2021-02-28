#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
  ll n;
  cin >> n;
  vector<ll> a(n);
  for(int i = 0; i < n; ++i)
  {
    cin >> a[i];
    a[i] -= (i + 1);
  }

  auto f = [&](ll b)
  {
    ll ret = 0;
    for(int i = 0; i < n; ++i)
    {
      ret += abs(a[i] - b);
    }
    return ret; 
  };

  ll le = -1000200001LL, re = 1000200001LL;
  ll lv = f(le);
  ll rv = f(re);
  while(re - le > 1)
  {
    ll mid = (le + re) / 2LL;
    ll mv = f(mid);
    if (lv < rv)
    {
      re = mid;
      rv = mv;
    }
    else
    {
      le = mid;
      lv = mv;
    }
  }
  cout << min(rv, lv);
}

int main()
{
  fastio;
  solve();

  return 0;
}