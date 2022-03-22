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

using mint = modint998244353;

void solve()
{
  ll n, m, k, s, t, x;
  cin >> n >> m >> k >> s >> t >> x;
  s--; t--; x--;
  vp edge(m);

  rep(i, m)
  {
    ll u, v;
    cin >> u >> v;
    u--; v--;
    edge[i] = make_pair(u, v);
  }

  // dp[i][j] = 偶奇が j のときの i への道のりの個数
  vector<vector<mint>> dp(n, vector<mint>(2));
  dp[s][0] = 1;
  rep(_, k)
  {
    vector<vector<mint>> nx(n, vector<mint>(2));
    rep(i, m)
    {
      auto [u, v] = edge[i];
      // u -> v
      if (v == x)
      {
        nx[v][1] += dp[u][0];
        nx[v][0] += dp[u][1];
      }
      else
      {
        nx[v][0] += dp[u][0];
        nx[v][1] += dp[u][1];
      }

      // v -> u
      if (u == x)
      {
        nx[u][1] += dp[v][0];
        nx[u][0] += dp[v][1];
      }
      else
      {
        nx[u][0] += dp[v][0];
        nx[u][1] += dp[v][1];
      }
    }
    dp = nx;
  }
  print(dp[t][0].val());
}

int main()
{
  fastio;
  solve();

  return 0;
}
