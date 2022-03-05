#include <bits/stdc++.h>
#include <atcoder/all>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i=(a);i<(ll)(n);++i)
#define repe(i,n) repie(i,0,n)
#define repie(i,a,n) for(ll i=(a);i<=(ll)(n);++i)
#define rrep(i,n) rrepi(i,n,0)
#define rrepi(i,n,a) for(ll i=(n);i>=(a);--i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()

using namespace std;
using namespace atcoder;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using P = pair<ll, ll>;
const ll INF = 1LL << 60;
void YN(bool a) { cout << (a ? "Yes" : "No") << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
void show(){ cout << endl; }
template <class Head, class... Tail>
void show(Head&& head, Tail&&... tail){ cout << head << " "; show(std::forward<Tail>(tail)...); }
template<class T> inline void showall(T& a) { for(auto v:a) cout<<v<<" "; cout<<endl; }

void solve()
{
  ll h, w, c;
  cin >> h >> w >> c;
  vvl mp(1010, vl(1010, INF));
  rep(y, h) rep(x, w)
  {
    cin >> mp[y][x];
  }

  ll ans = INF;

  // dp[y][x] = どこかに駅を建設していて (y, x) にいるときの最小値
  rep(_, 2)
  {
    vvl dp(1010, vl(1010, INF));

    repi(y, 1, h) dp[y][0] = min(dp[y - 1][0], mp[y - 1][0]) + c;
    repi(x, 1, w) dp[0][x] = min(dp[0][x - 1], mp[0][x - 1]) + c;

    repi(y, 1, h) repi(x, 1, w)
    {
      dp[y][x] = min(
        min(dp[y - 1][x], dp[y][x - 1]),
        min(mp[y - 1][x], mp[y][x - 1])
      ) + c;
    }

    rep(y, h) rep(x, w)
    {
      chmin(ans, dp[y][x] + mp[y][x]);
    }

    rep(y, h / 2)
    {
      swap(mp[y], mp[h - y - 1]);
    }
  }

  show(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}