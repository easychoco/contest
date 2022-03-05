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
  ll n, m;
  cin >> n >> m;
  vl h(n);
  rep(i, n) cin >> h[i];
  vvp graph(n);
  rep(i, m)
  {
    ll u, v;
    cin >> u >> v;
    u--; v--;

    ll score = h[u] - h[v];
    // u のほうが高いことにする
    if (score < 0) { swap(u, v); score = -score; }

    graph[u].pb(make_pair(0, v));
    graph[v].pb(make_pair(score, u));
  }

  ll INF = 1LL << 60;
  vl d(n, INF);
  d[0] = 0;

  // que<score, now>
  priority_queue<P, vp, greater<P>> que;
  que.push(P(0, 0));
  while(!que.empty())
  {
    auto [dist, now] = que.top();
    que.pop();
    if (d[now] < dist) continue;
    for (const auto& [cost, to] : graph[now])
    {
      if (chmin(d[to], d[now] + cost))
      {
        que.push(P(d[to], to));
      }
    }
  }
  rep(i, n) d[i] -= h[0] - h[i];
  print(-(*min_element(ALL(d))));
}

int main()
{
  fastio;
  solve();

  return 0;
}
