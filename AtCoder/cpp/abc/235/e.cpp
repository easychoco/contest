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
void debug(){ cerr << endl; }
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
  ll n, m, q;
  cin >> n >> m >> q;
  vt edges;
  rep(i, m)
  {
    ll a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    edges.pb(make_tuple(c, a, b));
  }

  // クエリ先読み
  vector<tuple<ll, ll, ll, ll>> query;
  rep(i, q)
  {
    ll u, v, w;
    cin >> u >> v >> w;
    u--; v--;
    query.pb(make_tuple(w, i, u, v));
  }

  UnionFind uf(n);
  sort(ALL(edges));
  sort(ALL(query));

  vb ans(q, false);
  ll qi = 0;
  // クラスカル法をやる
  rep(i, m)
  {
    auto[c, a, b] = edges[i];
    // クエリ分を尺取りっぽくつかう
    // クラスカル法で見ているコスト以下のノードを見て、
    // クラスカル法で追加できるノードだったら Yes
    while(qi < q && get<0>(query[qi]) <= c)
    {
      auto [w, i, u, v] = query[qi];
      ans[i] = !uf.same(u, v);
      qi++;
    }
    uf.unite(a, b);
  }

  rep(i, q)
  {
    YN(ans[i]);
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}
