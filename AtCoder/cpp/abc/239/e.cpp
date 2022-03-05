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

ll n, q;
vl x;
vvl graph;
vvl memo;

vl dfs(ll now, ll parent)
{
  if (!memo[now].empty()) return memo[now];

  priority_queue<ll> que;
  for(auto nx: graph[now])
  {
    if (nx == parent) continue;
    for(auto child: dfs(nx, now)) que.push(child);
  }

  que.push(x[now]);
  while(memo[now].size() < 20 && !que.empty())
  {
    memo[now].pb(que.top());
    que.pop();
  }
  return memo[now];
}

void solve()
{
  cin >> n >> q;

  x.resize(n);
  graph.resize(n);
  memo.resize(n);

  rep(i, n) cin >> x[i];
  rep(_, n - 1)
  {
    ll a, b;
    cin >> a >> b;
    a--; b--;

    graph[a].pb(b);
    graph[b].pb(a);
  }

  dfs(0, -1);

  rep(_, q)
  {
    ll v, k;
    cin >> v >> k;
    v--; k--;
    print(memo[v][k]);
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}
