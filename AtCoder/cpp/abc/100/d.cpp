#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
  ll n, m, xin, yin, zin;
  cin >> n >> m;
  vector<tuple<ll, ll, ll>> cake(n);
  for(int i = 0; i < n; ++i)
  {
    cin >> xin >> yin >> zin;
    cake[i] = make_tuple(xin, yin, zin);
  }

  ll ans = 0;
  for(int mask = 0; mask <= 8; mask++)
  {
    vector<ll> points;
    for(int i = 0; i < n; ++i)
    {
      ll x, y, z;
      tie(x, y, z) = cake[i];

      ll point = 0;
      point += ((mask & 0b001) > 0) ? x : -x;
      point += ((mask & 0b010) > 0) ? y : -y;
      point += ((mask & 0b100) > 0) ? z : -z;
      points.emplace_back(point);
    }

    sort(points.rbegin(), points.rend());
    auto st = points.begin();
    auto de = next( points.begin(), m);
    ans = max( ans, accumulate(st, de, 0LL) );
  }
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}