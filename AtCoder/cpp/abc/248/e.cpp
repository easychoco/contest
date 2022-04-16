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
using ll = int_fast64_t;
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
  ll n, k;
  cin >> n >> k;
  if (k == 1)
  {
    print("Infinity");
    return;
  }

  vp pos(n);
  rep(i, n)
  {
    ll x, y;
    cin >> x >> y;
    pos[i] = P(x, y);
  }

  // y = ax + b の a, b を保存
  set<vl> ans;
  vvl same(n);
  rep(i1, n)
  rep(i2, i1)
  {
    auto [x1, y1] = pos[i1];
    auto [x2, y2] = pos[i2];
    vl same{ i1, i2 };
    rep(i3, n)
    {
      if (i3 == i1 || i3 == i2) continue;
      auto [x3, y3] = pos[i3];

      // i1, i2 の傾き (x1 - x2) / (y1 - y2);
      // i1, i3 の傾き (x1 - x3) / (y1 - y3);

      // i1, i2, i3 が同一直線上にある
      if ((x1 - x2) * (y1 - y3) == (x1 - x3) * (y1 - y2))
      {
        same.pb(i3);
      }
    }

    if ((ll)same.size() >= k)
    {
      sort(ALL(same));
      ans.insert(same);
    }
  }
  print(ans.size());
}

int main()
{
  fastio;
  solve();

  return 0;
}
