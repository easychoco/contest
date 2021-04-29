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

vector< vector<ll> > graph;
vector<ll> group, color;
vector<bool> come(20, false);
ll cnt = 0;

// 連結成分に順番をつける
void dfs_grp(ll now)
{
  if (come[now]) return;

  come[now] = true;
  group.emplace_back(now);

  for(auto to : graph[now]) dfs_grp(to);
}

// つけた順番に沿って組み合わせを計算する
void dfs(ll idx)
{
  if (idx == (ll)group.size()) { cnt++; return; }
  ll now = group[idx];

  repie(c, 0, 2)
  {
    color[now] = c;
    bool ng = false;
    for(auto to : graph[now]) if (color[now] == color[to]) ng = true;
    if (ng) continue;
    dfs(idx + 1);
  }
  color[now] = -1;
}

void solve()
{
  ll n, m;
  cin >> n >> m;
  graph = vector<vector<ll>>(n);
  rep(i, m)
  {
    ll a, b;
    cin >> a >> b;
    a--; b--;
    graph[a].emplace_back(b);
    graph[b].emplace_back(a);
  }

  ll ans = 1;
  rep(i, n)
  {
    if (come[i]) continue;
    group.resize(0);
    dfs_grp(i);
    ll now = group[0];
    color = vector<ll>(n, -1);
    color[now] = 0;
    cnt = 0;
    dfs(1);
    ans *= 3 * cnt;
  }
  show(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}