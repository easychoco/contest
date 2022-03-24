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
  ll n, m;
  cin >> n >> m;
  vvl graph(n);
  rep(i, m)
  {
    ll u, v;
    cin >> u >> v;
    u--; v--;
    graph[u].pb(v);
    graph[v].pb(u);
  }

  vvl ans(1 << n, vl(n, INF));
  rep(i, n) ans[0][i] = 0;

  // T<dist, mask, last_node>
  queue<T> que;

  vl a(1 << n, INF);
  rep(i, n)
  {
    ans[1 << i][i] = 1;
    que.push(T(1, 1 << i, i));
  }

  a[0] = 0;
  rep(i, n) a[1 << i] = 1;

  while(!que.empty())
  {
    auto [dist, mask, last_node] = que.front();
    que.pop();

    for (auto u : graph[last_node])
    {
      // last_node から u に移動する
      ll b = mask ^ (1 << u);
      ll d = dist + 1;
      if (chmin(ans[b][u], d))
      {
        que.push(T(d, b, u));
        chmin(a[b], d);
      }
    }
  }
  print(accumulate(ALL(a), 0LL));
}

int main()
{
  fastio;
  solve();

  return 0;
}
