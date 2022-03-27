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

// SCC でループに含まれる頂点を抽出する
// 抽出した頂点からたどれる頂点は題意を満たすので
// DFS で探索する

// SCC : Strongly Connected Component
// 強連結成分分解 きょうれんけつせいぶんぶんかい
// O(V + E)
ll n, m;
vector< vector<ll> > graph; // 順方向の
vector< vector<ll> > graph_rev; // 逆方向
vector<ll> group; // 各ノードがどのグループに属するか
vector<ll> seq; // 帰りがけ順の並び
vector<bool> come;
vector<ll> hist; // 各グループに属する

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
vl scc_get_loop_node()
{
  vl ret;
  rep(i, n) if (hist[group[i]] > 1) ret.pb(i);
  return ret;
}

ll ans = 0;
void dfs(ll now)
{
  if (come[now]) return;
  come[now] = true;
  ans++;
  for (auto next : graph_rev[now]) dfs(next);
}

void solve()
{
  cin >> n >> m;
  graph.resize(n);
  graph_rev.resize(n);
  group.resize(n, 0);
  come.resize(n, false);
  hist.resize(n, 0);
  rep(i, m)
  {
    ll a, b;
    cin >> a >> b;
    a--; b--;
    graph[a].emplace_back(b);
    graph_rev[b].emplace_back(a);
  }

  fill(ALL(come), false);
  rep(i, n)
  {
    scc_dfs(i);
  }

  fill(ALL(come), false);
  ll group_id = 0;
  for(ll i = seq.size() - 1; i >= 0; --i)
  {
    scc_dfs_rev(seq[i], group_id++);
  }

  fill(ALL(come), false);
  for (auto now : scc_get_loop_node())
  {
    dfs(now);
  }
  print(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}
