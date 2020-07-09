#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
  int x, y, z, k;
  cin >> x >> y >> z >> k;
  vector<ll> a(x), b(y), c(z);
  for(int i = 0; i < x; ++i) cin >> a[i];
  for(int i = 0; i < y; ++i) cin >> b[i];
  for(int i = 0; i < z; ++i) cin >> c[i];
  sort(a.begin(), a.end(), greater<ll>());
  sort(b.begin(), b.end(), greater<ll>());
  sort(c.begin(), c.end(), greater<ll>());

  auto f = [&](ll arg)
  {
    int cnt = 0;
    for(int ia = 0; ia < x; ++ia)
    {
      for(int ib = 0; ib < y; ++ib)
      {
        for(int ic = 0; ic < z; ++ic)
        {
          if (a[ia] + b[ib] + c[ic] >= arg) cnt++;
          else break;
          if (k <= cnt) return true;
        }
      }
    }
    return false;
  };

  ll le = -1, re = 30000000005LL;
  while(re - le > 1)
  {
    ll mid = (le + re) / 2;
    if ( !f(mid) ) re = mid;
    else le = mid;
  }

  vector<ll> ans;
  for(int ia = 0; ia < x; ++ia)
  {
    for(int ib = 0; ib < y; ++ib)
    {
      for(int ic = 0; ic < z; ++ic)
      {
        ll sum = a[ia] + b[ib] + c[ic];
        if (sum > le) ans.emplace_back(sum);
        else break;
      }
    }
  }

  sort(ans.begin(), ans.end(), greater<ll>());
  while(ans.size() < k)
  {
    ans.emplace_back(le);
  }
  for(const auto& v : ans)
  {
    cout << v << endl;
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}