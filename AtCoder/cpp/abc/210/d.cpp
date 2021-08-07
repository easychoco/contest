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

  // dp[y][x] = どこかに駅を建設していて (i, j) にいるときの最小値
  vvl dp(1010, vl(1010, INF));
  rep(i, 4)
  {
    rep(y, h) rep(x, w)
    {
      dp[y + 1][x + 1] = min(mp[y + 1][x + 1], min(dp[y][x + 1], dp[y + 1][x]) + c);
    }

    rep(y, h) rep(x, w)
    {
      chmin(ans, min(dp[y][x + 1], dp[y + 1][x]) + c + mp[y + 1][x + 1]);
    }

    rep(y, 1001)
    rep(x, 1001)
    {
      swap(dp[y][x], dp[x][1000 - y]);
      swap(mp[y][x], mp[x][1000 - y]);
    }
    swap(h, w);
  }

  show(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}