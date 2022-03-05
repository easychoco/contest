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
void show(){ cout << endl; }
template <class Head, class... Tail>
void show(Head&& head, Tail&&... tail){ cout << head << " "; show(std::forward<Tail>(tail)...); }
void showd(double d){ cout << std::fixed<<setprecision(13) << d << endl; }
template<class T> inline void showall(T& a) { for(auto v:a) cout<<v<<" "; cout<<endl; }

class UnionFind{
public:
  vector<ll> p;		// 親
  vector<ll> rank;	// サイズ・各集合の根のみ有効
  ll root_num; // 連結成分の数
  UnionFind(ll n) : root_num(n) {
    p.resize(n, -1);
    rank.resize(n, 1);
  }
  ll root(ll x){
    if(p[x] == -1) return x;
    else return p[x] = root(p[x]); // 深さを 1 にしている
  }
  bool unite(ll x, ll y){
    x = root(x); y = root(y);
    if(x == y) return false;
    if(rank[x] > rank[y]) swap(x, y); // rankの小さいものを下につける
    rank[y] += rank[x];
    p[x] = y;
    root_num--;
    return true;
  }
  // グループごとに頂点をまとめる: O(N log N)
  map<ll, vector<ll>> groups(){
    map<ll, vector<ll>> ret;
    rep(i, p.size()) ret[root(i)].emplace_back(i);
    return ret;
  }
  //xが属すグループのサイズ
  ll size(ll x){ return rank[root(x)]; }
  bool same(ll x, ll y){ return (root(x) == root(y)); }
};

vvp graph;
stack<T> tmp;

bool dfs(ll now, ll to, ll parent)
{
  if (now == to) return true;
  for (auto [next, idx] : graph[now])
  {
    if (parent == next) continue;
    if (dfs(next, to, now))
    {
      tmp.push(make_tuple(now, next, idx));
      return true;
    }
  }
  return false;
}

void solve()
{
  ll n, m;
  cin >> n;

  graph.resize(n);
  vl deg(n); // 次数
  vl p(n);   // いまの数列
  vb fix(n, false); // 固定された
  UnionFind uf(n);

  rep(i, n)
  {
    cin >> p[i];
    p[i]--;
  }

  cin >> m;
  rep(i, m)
  {
    ll a, b;
    cin >> a >> b;
    a--; b--;
    // 橋だけにする
    if (!uf.same(a, b))
    {
      uf.unite(a, b);
      graph[a].eb(b, i + 1);
      graph[b].eb(a, i + 1);
      deg[a]++;
      deg[b]++;
    }
  }

  rep(i, n)
  {
    // ソートできない
    if (uf.root(i) != uf.root(p[i]))
    {
      show(-1);
      return;
    }
  }

  vl ans;
  for (auto mp : uf.groups())
  {
    vl vec = mp.second;
    ll sz = vec.size();
    rep(_, sz)
    {
      // いちばん次数が低い頂点
      ll to_idx = 0;
      ll sc = INF;
      rep(i, sz)
      {
        if (!fix[vec[i]] && deg[vec[i]] < sc)
        {
          sc = deg[vec[i]];
          to_idx = vec[i];
        }
      }

      // to_idx の数値がある頂点
      ll now_idx = 0;
      rep(i, sz) if (p[vec[i]] == to_idx) now_idx = vec[i];

      // now_idx を to_idx にもってくる
      // dfs は O (N)
      // 全体で O (N^2)
      // N < 1000 なので計算量は大丈夫
      dfs(now_idx, to_idx, -1);

      // dfs の結果を適用
      // 正解のパスにある枝を行きがけで採用したい
      while(!tmp.empty())
      {
        auto [now, next, idx] = tmp.top();
        ans.pb(idx);
        swap(p[now], p[next]);
        tmp.pop();
      }

      // 次数を更新
      for (auto [next, idx] : graph[to_idx])
      {
        if (!fix[next])
        {
          deg[next]--;
        }
      }
      deg[to_idx] = INF;

      // このループで使ったので固定する
      fix[to_idx] = true;
    }
  }

  show(ans.size());
  showall(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}
