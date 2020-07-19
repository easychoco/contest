#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

ll calcDiff(ll cx, ll cy, ll x, ll y)
{
  return abs(x - cx) + abs(y - cy);
}

void solve()
{
  ll n, x, y, h;
  cin >> n;
  vector<tuple<ll, ll, ll>> a(n);
  for(int i = 0; i < n; ++i)
  {
    cin >> x >> y >> h;
    a[i] = make_tuple(h, x, y);
  }

  sort(a.rbegin(), a.rend());

  for(ll cx = 0; cx <= 100; ++cx)
  {
    for(ll cy = 0; cy <= 100; ++cy)
    {
      bool ok = true;
      ll ch = calcDiff(cx, cy, get<1>(a[0]), get<2>(a[0])) + get<0>(a[0]);
      for(const auto& t : a)
      {
        ll diff = calcDiff(cx, cy, get<1>(t), get<2>(t));
        ok &= ( ( ch == diff + get<0>(t) ) || (diff > ch && get<0>(t) == 0) );
      }
      if (ok)
      {
        cout << cx << " " << cy << " " << ch;
        return;
      }
    }
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}