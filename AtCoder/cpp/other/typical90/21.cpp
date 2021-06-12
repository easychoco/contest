#include <bits/stdc++.h>
#include <atcoder/all>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i=a;i<(ll)n;++i)
#define repe(i,n) repie(i,0,n)
#define repie(i,a,n) for(ll i=a;i<=(ll)n;++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()

using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<ll, ll>;
void YN(bool a) { cout << (a ? "Yes" : "No") << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
void show(){ cout << endl; }
template <class Head, class... Tail>
void show(Head&& head, Tail&&... tail){ cout << head << " "; show(std::forward<Tail>(tail)...); }
template<class T> inline void showall(T& a) { for(auto v:a) cout<<v<<" "; cout<<endl; }

// SCC : Strongly Connected Component
// 強連結成分分解 きょうれんけつせいぶんぶんかい
// O(V + E)
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
  come[now] = true;
  for (const auto& next : graph[now])
  {
    if (!come[next]) scc_dfs(next);
  }
  seq.emplace_back(now);
}

// 2回目の DFS
// 記録した番号の大きい順にDFSをして、訪れたノードが強連結成分
void scc_dfs_rev(ll now, ll grp)
{
  come[now] = true;
  group[now] = grp;
  hist[grp]++;
  for (const auto& next : graph_rev[now])
  {
    if (!come[next]) scc_dfs_rev(next, grp);
  }
}

void solve()
{
  ll n, m;
  cin >> n >> m;
  graph.resize(n, vector<ll>());
  graph_rev.resize(n, vector<ll>());
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
    if (!come[i]) scc_dfs(i);
  }

  fill(ALL(come), false);
  ll grp = 0;
  for(ll i = seq.size() - 1; i >= 0; --i)
  {
    if (!come[seq[i]]) scc_dfs_rev(seq[i], grp++);
  }

  ll ans = 0;
  rep(i, grp)
  {
    ans += hist[i] * (hist[i] - 1) / 2;
  }
  show(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}