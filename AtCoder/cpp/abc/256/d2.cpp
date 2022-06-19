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

// C++20 の　std::ranges::range で書きたい
class SegmentMap{
public:
  vector<T> raw; // vector< pair< from, to > >
  void add(ll from, ll to) { add(P(from, to)); }
  void add(P segment) { raw.pb(make_tuple(segment.first, segment.second, (ll)raw.size())); }

  // 区間スケジューリング
  // O ( N log N )
  vector<T> schedule() {
    vector<T> ret;
    vector<T> segments(raw);
    sort(segments.begin(), segments.end(), [&](const T &a, const T &b) { return get<1>(a) < get<1>(b); });
    ll last = get<1>(segments[0]);
    ret.pb(segments[0]);
    for (auto seg : segments) {
      auto [from, to, idx] = seg;
      if (last < from) {
        ret.pb(seg);
        last = to;
      }
    }
    return ret;
  } 

  // 区間を合成したもの
  // O ( N log N )
  vector<P> composite() {
    vector<P> ret;
    vector<T> segments(raw);
    sort(ALL(segments));
    auto [from, to, _] = segments[0];
    for (auto seg : segments) {
      auto [pf, pt, _] = seg;
      if (pf <= to) chmax(to, pt);
      else {
        ret.eb(from, to);
        from = pf;
        to = pt;
      }
    }
    ret.eb(from, to);
    return ret;
  }
};

void solve()
{
  ll n;
  cin >> n;
  SegmentMap seg;
  rep(i, n)
  {
    ll l, r;
    cin >> l >> r;
    seg.add(P(l, r));
  }
  vp ans = seg.composite();
  printp(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}
