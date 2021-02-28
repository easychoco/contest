#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

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
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  vector<ll> b(a);
  repi(i, 1, n) b[i] += b[i - 1];
  
  ll ans = 1LL << 60;
  for(int i = 1; i < n - 2; ++i)
  {
    // iで左右に切る
    ll lsum = b[i];
    ll rsum = b[n - 1] - b[i];

    auto litr = lower_bound(ALL(b), lsum / 2);
    ll ldist = distance(b.begin(), litr);
    ll l1 = 1LL << 60, l2 = 0;
    rep(ii, 2)
    {
      ll llsum = b[ldist - ii];
      ll lrsum = lsum - llsum;
      if (abs(l1 - l2) > abs(lrsum - llsum))
      {
        l1 = llsum;
        l2 = lrsum;
      }
      if (ldist == 0) break;
    }

    auto ritr = lower_bound(ALL(b), lsum + rsum / 2);
    ll rdist = distance(b.begin(), ritr);
    ll r1 = 1LL << 60, r2 = 0;
    rep(ii, 2)
    {
      ll rlsum = b[rdist - ii] - lsum;
      ll rrsum = rsum - rlsum;
      if (abs(r1 - r2) > abs(rrsum - rlsum))
      {
        r1 = rlsum;
        r2 = rrsum;
      }
      if (rdist == 0) break;
    }

    ll score = max({l1, l2, r1, r2}) - min({l1, l2, r1, r2});
    chmin(ans, score);
  }
  cout << ans << endl;
}

int main()
{
  fastio;
  solve();

  return 0;
}