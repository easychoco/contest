#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
  int n, m, a, b;
  cin >> n >> m;
  vector< pair<ll, ll> > d(n);
  for(int i = 0; i < n; ++i)
  {
    cin >> a >> b;
    d[i] = make_pair(a, b);
  }
  sort(d.begin(), d.end());

  ll ans = 0;
  ll cnt = 0;
  for(int i = 0; i < n; ++i)
  {
    if (cnt + d[i].second < m)
    {
      ans += d[i].first * d[i].second;
      cnt += d[i].second;
    }
    else
    {
      ans += d[i].first * (m - cnt);
      break;
    }
  }
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}