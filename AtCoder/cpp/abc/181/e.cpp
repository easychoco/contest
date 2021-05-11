#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i=a;i<(ll)n;++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define Show(val) cout<<(val)<<" "
#define Showln(val) cout<<(val)<<endl

using namespace std;
using ll = long long;
using P = pair<ll, ll>;
// using P = pair<int, int>;
void YN(bool a) { cout << (a ? "Yes" : "No"); }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

void solve()
{
  ll n, m;
  cin >> n >> m;
  vector<ll> h(n), w(m);
  rep(i, n) cin >> h[i];
  rep(i, m) cin >> w[i];

  sort(ALL(h));

  if (n == 1)
  {
    ll ans = 1LL << 60;
    rep(i, m) ans = min(ans, abs(h[0] - w[i]));
    cout << ans;
    return;
  }

  vector<ll> diff(n - 1);
  rep(i, n - 1) diff[i] = h[i + 1] - h[i];

  vector<ll> b1(n / 2), b2(n / 2);
  b1[0] = diff[0];
  b2[0] = diff[1];
  repi(i, 1, n / 2) b1[i] = b1[i - 1] + diff[i * 2];
  repi(i, 1, n / 2) b2[i] = b2[i - 1] + diff[i * 2 + 1];

  ll ans = 1LL << 60;
  rep(i, m)
  {
    auto itr = lower_bound(ALL(h), w[i]);
    ll dist = distance(h.begin(), itr);
    ll score = 0;

    if (dist & 1) score += w[i] - h[dist - 1];
    else score += h[dist] - w[i];

    ll score_f = 0, score_b = 0;
    if (dist / 2 >= 1) score_f = b1[dist / 2 - 1];
    if (dist / 2 >= 1) score_b = b2[n / 2 - 1] - b2[dist / 2 - 1];
    else score_b = b2[n / 2 - 1];

    score += score_f + score_b;
    chmin(ans, score);
  }
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}