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
  bool merge(ll x, ll y){ return unite(x, y); }
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

ll n;
ll toIdx(ll idx, bool isA)
{
  return idx + n * isA;
}

void solve()
{
  cin >> n;
  vl a(n), b(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];

  UnionFind uf(2 * n);
  set<ll> st_a;
  set<ll> st_b;

  st_a.insert(a[0]);
  st_b.insert(b[0]);
  if (st_a == st_b) uf.unite(toIdx(0, true), toIdx(0, false));
  ll bi = 1;
  repi(ai, 1, n)
  {
    if (!st_a.insert(a[ai]).second)
    {
      // すでに含まれていた
      uf.unite(toIdx(ai - 1, true), toIdx(ai, true));
      continue;
    }

    // a[ai] が新しく追加された
    while (bi < n && st_a.find(b[bi]) != st_a.end())
    {
      if (!st_b.insert(b[bi]).second)
      {
        // すでに含まれていた
        uf.unite(toIdx(bi - 1, false), toIdx(bi, false));
      }
      bi++;
    }

    if (st_a.size() != st_b.size()) continue;
    uf.unite(toIdx(ai, true), toIdx(bi - 1, false));
  }

  ll q;
  cin >> q;
  rep(_, q)
  {
    ll x, y;
    cin >> x >> y;
    x--; y--;
    YN(uf.same(toIdx(x, true), toIdx(y, false)));
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}
