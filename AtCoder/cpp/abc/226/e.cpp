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
template<class T> inline void showall(T& a) { for(auto v:a) cout<<v<<" "; cout<<endl; }

using mint = modint998244353;

class UnionFind{
public:
  vector<ll> p;		// 親
  vector<ll> rank;	// サイズ・各集合の根のみ有効
  vector<ll> same_num;
  UnionFind(ll n){
    p.resize(n, -1);
    rank.resize(n, 1);
    same_num.resize(n, 0);
  }
  ll root(ll x){
    if(p[x] == -1) return x;
    else return p[x] = root(p[x]); // 深さを 1 にしている
  }
  bool unite(ll x, ll y){
    x = root(x); y = root(y);
    if(x == y)
    {
      same_num[x] += 1;
      return false;
    }
    if(rank[x] > rank[y]) swap(x, y); // rankの小さいものを下につける
    rank[y] += rank[x];
    same_num[y] += same_num[x];
    p[x] = y;
    return true;
  }
  // グループの数
  ll root_num() {
    ll num = 0;
    for(ll x : p) if (x < 0) num++;
    return num;
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
  if (n != m)
  {
    show(0);
    return;
  }

  ll same_num = 0;
  UnionFind uf(n);
  rep(i, m)
  {
    ll u, v;
    cin >> u >> v;
    u--; v--;
    if (uf.same(u, v)) same_num++;
    uf.unite(u, v);
  }

  for (auto v : uf.same_num)
  {
    if (v > 1)
    {
      show(0);
      return;
    }
  }
  mint ans = mint(2).pow(uf.root_num());
  show(ans.val());
}

int main()
{
  fastio;
  solve();

  return 0;
}
