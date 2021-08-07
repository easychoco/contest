#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const ll INF = 1LL << 60;
const double PI = 3.14159265358979;

void solve()
{
  int a, b, q;
  cin >> a >> b >> q;
  vector<ll> s(a), t(b);
  for(int i = 0; i < a; ++i) cin >> s[i];
  for(int i = 0; i < b; ++i) cin >> t[i];

  ll x;
  for(int i = 0; i < q; ++i)
  {
    cin >> x;
    int ans = 0;
    auto s_it = lower_bound(s.begin(), s.end(), x);
    auto t_it = lower_bound(t.begin(), t.end(), x);

    ll sr = INF, tr = INF, sl = -INF, tl = -INF;
    if (s_it != s.end()) sr = *s_it;
    if (t_it != t.end()) tr = *t_it;
    if (s_it != s.begin()) { s_it--; sl = *s_it; }
    if (t_it != t.begin()) { t_it--; tl = *t_it; }
    
    ll straight_dist = INF, turn_dist = INF;

    // min( 左直進, 右直進 )
    straight_dist  = abs( min( x - min(sl, tl), max(sr, tr) - x) );

    // t左->s右
    ll dist_tlsr = abs(x - tl + sr - tl);
    // s左->t右
    ll dist_sltr = abs(x - sl + tr - sl);
    // t右->s左
    ll dist_trsl = abs(tr - x + tr - sl);
    // s右->t左
    ll dist_srtl = abs(sr - x + sr - tl);

    turn_dist = min({dist_tlsr, dist_sltr, dist_trsl, dist_srtl});

    cout << min(straight_dist, turn_dist) << endl;
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}