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
  ll n;
  cin >> n;
  vt node(n);
  rep(i, n)
  {
    ll x, y, p;
    cin >> x >> y >> p;
    node[i] = make_tuple(x, y, p);
  }
  vector< vector<ll> > dist(n, vector<ll>(n, 0));
  rep (fi, n)
  rep (ti, n)
  {
    if (fi == ti) continue;
    auto [fx, fy, fp] = node[fi];
    auto [tx, ty, tp] = node[ti];

    dist[fi][ti] = (abs(fx - tx) + abs(fy - ty) - 1) / fp + 1;
  }

  rep (k, n){       // 経由する頂点
    rep (i, n) {    // 始点
      rep (j, n) {  // 終点
        chmin(dist[i][j], max(dist[i][k], dist[k][j]));
      }
    }
  }

  ll ans = INF;
  rep(fi, n)
  {
    ll score = 0;
    rep(ti, n) chmax(score, dist[fi][ti]);
    chmin(ans, score);
  }
  print(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}
