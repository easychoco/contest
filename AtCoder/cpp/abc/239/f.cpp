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

#define bye {print(-1);return;}

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

void solve()
{
  ll n, m;
  cin >> n >> m;
  vl d(n);
  vvl graph(n);
  rep(i, n) cin >> d[i];
  UnionFind uf(n);

  rep(i, m)
  {
    ll a, b;
    cin >> a >> b;
    a--; b--;
    graph[a].pb(b);
    graph[b].pb(a);
    uf.unite(a, b);
  }

  vvl temp(n);
  rep(i, n)
  {
    if (d[i] < (ll)graph[i].size()) bye;
    rep(_, d[i] - graph[i].size()) temp[uf.root(i)].pb(i);
  }

  vl g1;
  vvl g2;
  rep (i, n)
  {
    if ((ll)temp[i].size() == 1) g1.pb(temp[i][0]);
    if ((ll)temp[i].size()  > 1) g2.pb(temp[i]);
  }

  vp ans;
  for (auto g : g2)
  {
    rep(i, g.size() - 1)
    {
      if (g1.empty()) bye;
      uf.unite(g[i], g1.back());
      ans.pb(P(g[i] + 1, g1.back() + 1));
      g1.pop_back();
    }
    g1.pb(g.back());
  }

  if (g1.size() != 2) bye;

  uf.unite(g1[0], g1[1]);
  ans.pb(P(g1[0] + 1, g1[1] + 1));

  if (uf.root_num > 1) bye;

  printvp(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}
