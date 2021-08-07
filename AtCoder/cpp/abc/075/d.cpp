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
  ll n, k;
  cin >> n >> k;
  vector<ll> x(n), y(n);
  rep(i, n)
  {
    cin >> x[i] >> y[i];
  }

  ll ans = 1LL << 62;

  // 50 C 4 = 230,300 = 2.3 * 10^5
  for(int i1 = 0; i1 < n; ++i1)
  for(int i2 = 0; i2 < i1; ++i2)
  for(int i3 = 0; i3 <= i2 - (k > 2); ++i3)
  for(int i4 = 0; i4 <= i3 - (k > 3); ++i4)
  {
    ll xl = min({x[i1], x[i2], x[i3], x[i4]});
    ll xr = max({x[i1], x[i2], x[i3], x[i4]});
    ll yl = min({y[i1], y[i2], y[i3], y[i4]});
    ll yr = max({y[i1], y[i2], y[i3], y[i4]});

    ll cnt = 0;
    rep(i, n)
    {
      cnt += (xl <= x[i] && x[i] <= xr && yl <= y[i] && y[i] <= yr);
    }

    if (cnt >= k)
    {
      ll area = (xr - xl) * (yr - yl);
      chmin(ans, area);
    }
  }
  cout << ans << endl;
}

int main()
{
  fastio;
  solve();

  return 0;
}