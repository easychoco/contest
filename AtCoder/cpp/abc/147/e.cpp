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
#define pb push_back
#define eb emplace_back

using namespace std;
using namespace atcoder;
using vb = vector<bool>;
using vvb = vector<vb>;
// using ll = int_fast64_t;
using ll = short;
using vl = vector<ll>;
using vvl = vector<vl>;
using P = pair<ll, ll>;
using vp = vector<P>;
using vvp = vector<vp>;
using T = tuple<ll, ll, ll>;
using vt = vector<T>;
const ll INF = 1LL << 60;
void YN(bool a) { cout << (a ? "Yes" : "No") << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
void print() { cout << endl; }
template <class Head, class... Tail>
void print(Head &&head, Tail &&...tail){ cout << head << " "; print(std::forward<Tail>(tail)...); }
void printd(double d) { cout << std::fixed << setprecision(13) << d << endl; }
template <class T>
inline void printv(T &v){ for (auto a : v) print(a); }
template <class T>
inline void printvp(T &p){ for (auto [a, b] : p) print(a, b); }
template <class T>
inline void printvt(T &t){ for (auto [a, b, c] : t) print(a, b, c); }
void debug() { cerr << endl; }
template <class Head, class... Tail>
void debug(Head&& head, Tail&&... tail){ cerr << head << " "; debug(std::forward<Tail>(tail)...); }

void solve()
{
  ll h, w;
  cin >> h >> w;
  vvl mp(h, vl(w));
  
  rep(y, h)
  rep(x, w)
  {
    cin >> mp[y][x];
  }
  rep(y, h)
  rep(x, w)
  {
    ll b;
    cin >> b;
    mp[y][x] = abs(mp[y][x] - b);
  }

  constexpr ll BASE = 80 * 80;

  // dp[y][x][v] = (y, x) に来た時の和が v になるか
  vector<vvl> dp(h, vvl(w, vl(BASE * 2 + 1, 0)));

  dp[0][0][BASE + mp[0][0]] = 1;
  dp[0][0][BASE - mp[0][0]] = 1;

  rep(y, h)
  rep(x, w)
  {
    if (y < h - 1)
    {
      ll ny = y + 1;
      ll nx = x;
      repe(v, BASE * 2)
      {
        if (dp[y][x][v] == 0) continue;
        if (v - mp[ny][nx] >= 0)       dp[ny][nx][v - mp[ny][nx]] += 1;
        if (v + mp[ny][nx] <= BASE * 2) dp[ny][nx][v + mp[ny][nx]] += 1;
      }
    }
    if (x < w - 1)
    {
      ll ny = y;
      ll nx = x + 1;
      repe(v, BASE * 2)
      {
        if (dp[y][x][v] == 0) continue;
        if (v - mp[ny][nx] >= 0)       dp[ny][nx][v - mp[ny][nx]] += 1;
        if (v + mp[ny][nx] <= BASE * 2) dp[ny][nx][v + mp[ny][nx]] += 1;
      }
    }
  }
  repe(i, BASE)
  {
    if (dp[h - 1][w - 1][BASE - i] > 0 || dp[h - 1][w - 1][BASE + i] > 0)
    {
      print(i);
      return;
    }
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}
