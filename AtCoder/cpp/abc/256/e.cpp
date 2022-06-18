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

// SCC : Strongly Connected Component
// 強連結成分分解 きょうれんけつせいぶんぶんかい
// O(V + E)
ll n;
vector< vector<ll> > graph; // 順方向
vector< vector<ll> > graph_rev; // 逆方向
vector<bool> come;
vector<ll> seq; // 帰りがけ順の並び
vector<ll> hist; // 各グループのサイズ
vector<ll> group; // 各ノードがどのグループに属するか

// 1回目の DFS
// 帰りがけ順に記録する
void scc_dfs(ll now)
{
  if (come[now]) return;
  come[now] = true;
  for (const auto& next : graph[now])
  {
    scc_dfs(next);
  }
  seq.emplace_back(now);
}

// 2回目の DFS
// 記録した番号の大きい順にDFSをして、訪れたノードが強連結成分
void scc_dfs_rev(ll now, ll group_id)
{
  if (come[now]) return;
  come[now] = true;
  group[now] = group_id;
  hist[group_id]++;
  for (const auto& next : graph_rev[now])
  {
    scc_dfs_rev(next, group_id);
  }
}

// 閉路に含まれる要素を返す
// O(N)
vl scc_get_loop_node()
{
  vl ret;
  rep(i, n) if (hist[group[i]] > 1) ret.pb(i);
  return ret;
}

void solve()
{
  cin >> n;
  vl x(n), c(n);
  rep(i, n) cin >> x[i];
  rep(i, n) cin >> c[i];

  graph.resize(n);
  graph_rev.resize(n);
  group.resize(n, 0);
  come.resize(n, false);
  hist.resize(n, 0);

  rep(i, n)
  {
    x[i]--;
    graph[i].pb(x[i]);
    graph_rev[x[i]].pb(i);
  }

  fill(ALL(come), false);
  rep(i, n)
  {
    if (!come[i]) scc_dfs(i);
  }

  fill(ALL(come), false);
  ll group_id = 0;
  for(ll i = seq.size() - 1; i >= 0; --i)
  {
    if (!come[seq[i]]) scc_dfs_rev(seq[i], group_id++);
  }

  // hist が 2 以上のグループは閉路・ループになっている
  vl looping = scc_get_loop_node();

  vl score(n, INF);
  for (auto v : looping)
  {
    chmin(score[group[v]], c[v]);
  }

  ll ans = 0;
  rep(i, n) ans += score[i] % INF;
  print(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}
