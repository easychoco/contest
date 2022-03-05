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

using namespace std;
using namespace atcoder;
using ll = int_fast64_t;
using vl = vector<ll>;
using vvl = vector<vl>;
using P = pair<ll, ll>;
using vp = vector<P>;
using vvp = vector<vp>;
const ll INF = 1LL << 60;
void YN(bool a) { cout << (a ? "Yes" : "No") << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
void show(){ cout << endl; }
template <class Head, class... Tail>
void show(Head&& head, Tail&&... tail){ cout << head << " "; show(std::forward<Tail>(tail)...); }
template<class T> inline void showall(T& a) { for(auto v:a) cout<<v + 1<<" "; cout<<endl; }

// https://atcoder.jp/contests/abc198/tasks/abc198_e
vvl graph;
vector<ll> color;
vector<ll> shown(100010, 0);
set<ll> ans;
void dfs(ll now, ll parent)
{
  if (shown[color[now]] == 0) ans.insert(now);
  shown[color[now]]++;
  for (auto next : graph[now])
  {
    if (next == parent) continue;
    dfs(next, now);
  }
  shown[color[now]]--;
}

void solve()
{
  ll n;
  cin >> n;
  graph.resize(n);
  color.resize(n);

  rep(i, n) cin >> color[i];
  rep(i, n - 1)
  {
    ll a, b;
    cin >> a >> b;
    a--; b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  dfs(0, -1);
  showall(ans);
}

/*
// https://atcoder.jp/contests/abc073/tasks/abc073_d
void solve()
{
  ll n, m, r;
  cin >> n >> m >> r;
  vl pos(r);
  vector< vector<ll> > dist(n, vector<ll>(n, INF));
  rep(i, r)
  {
    cin >> pos[i];
    pos[i]--;
  }
  rep(i, m)
  {
    ll a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    dist[a][b] = c;
    dist[b][a] = c;
  }

  rep(i, n) dist[i][i] = 0;
  rep (k, n){       // 経由する頂点
    rep (i, n) {    // 始点
      rep (j, n) {  // 終点
        chmin(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  vvl graph(r, vl(r, 0));
  rep(i, r)
  rep(j, r)
  {
    graph[i][j] = dist[pos[i]][pos[j]];
    graph[j][i] = dist[pos[j]][pos[i]];
  }

  vl route(r, 0);
  iota(ALL(route), 0);
  ll ans = INF;
  do {
    ll score = 0;
    rep(i, r - 1)
    {
      score += graph[route[i]][route[i + 1]];
    }
    chmin(ans, score);
  } while(next_permutation(ALL(route)));
  show(ans);
}
*/

int main()
{
  fastio;
  solve();

  return 0;
}
