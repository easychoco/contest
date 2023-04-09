#include <bits/stdc++.h>
#include <atcoder/all>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i=(a);i<(ll)(n);++i)
#define repe(i,n) repie(i,0,n)
#define repie(i,a,n) for(ll i=(a);i<=(ll)(n);++i)
#define rrep(i,n) rrepi(i,n,0)
#define rrepi(i,n,a) for(ll i=(n);i>=(ll)(a);--i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define pb push_back
#define eb emplace_back

using namespace std;
using namespace atcoder;
using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vs = vector<string>;
using vl = vector<ll>;
using vvl = vector<vl>;
using P = pair<ll, ll>;
using vp = vector<P>;
using vvp = vector<vp>;
using T = tuple<ll, ll, ll>;
using vt = vector<T>;
const ll INF = 1LL << 60;
void YN(bool a, string whenT="Yes", string whenF="No") { cout << (a ? whenT : whenF) << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
void print() { cout << endl; }
template <class T>
void print(T &&t){ cout << t << endl; }
template <class Head, class... Tail>
void print(Head &&head, Tail &&...tail){ cout << head << " "; print(std::forward<Tail>(tail)...); }
void printd(double d) { cout << std::fixed << setprecision(13) << d << endl; }
template <class T>
inline void printv(T &v){ for (auto a : v) print(a); }
template <class T>
inline void printp(T &p){ for (auto [a, b] : p) print(a, b); }
template <class T>
inline void printt(T &t){ for (auto [a, b, c] : t) print(a, b, c); }
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

  auto check = [&](ll y, ll x) -> bool {
    bool le = x > 0 ? (mp[y][x] != mp[y][x - 1]) : true;
    bool up = y > 0 ? (mp[y][x] != mp[y - 1][x]) : true;

    bool ri = x < w - 1 ? (mp[y][x] != mp[y][x + 1]) : true;
    bool dw = y < h - 1 ? (mp[y][x] != mp[y + 1][x]) : true;

    bool ret = le && up && ri && dw;
    // if (ret) print(y, x);
    return ret;
  };

  ll cnt = 0;
  rep(y, h)
  {
    // print("y", y);
    bool flip = false;
    rep(x, w) flip |= check(y, x);
    if (flip)
    {
      // print("y-flip", y);
      cnt += 1;
      rep(x, w) mp[y][x] = 1 - mp[y][x];
      repie(yy, max(0LL, y - 1), y) rep(x, w) { if(check(yy, x)) { print(-1); return; } }
    }
  }

  print(min(cnt, h - cnt));
}

int main()
{
  fastio;
  solve();

  return 0;
}
