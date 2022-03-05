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
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using P = pair<ll, ll>;
const ll INF = 1LL << 60;
void YN(bool a) { cout << (a ? "Yes" : "No") << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
void show(){ cout << endl; }
template <class Head, class... Tail>
void show(Head&& head, Tail&&... tail){ cout << head << " "; show(std::forward<Tail>(tail)...); }
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

ll to(ll y , ll x)
{
  return y * 4 + x;
}

bool ok(ll mask, ll y, ll x)
{
  return mask >> to(y, x) & 1;
}

void solve()
{
  vl target;
  vvl mp(4, vl(4));
  rep(y, 4)
  rep(x, 4)
  {
    cin >> mp[y][x];
    if (mp[y][x] == 1) target.push_back(to(y, x));
  }

  ll ans = 0;
  rep(mask, 1 << 16)
  {
    UnionFind uf(17);
    rep(y, 4)
    rep(x, 4)
    {
      bool t = ok(mask, y, x);
      if (x < 3 && t == ok(mask, y, x + 1)) { uf.unite(to(y, x), to(y, x + 1)); }
      if (y < 3 && t == ok(mask, y + 1, x)) { uf.unite(to(y, x), to(y + 1, x)); }
    }
    rep(y, 4)
    {
      if (!ok(mask, y, 0)) uf.unite(16, to(y, 0));
      if (!ok(mask, y, 3)) uf.unite(16, to(y, 3));
    }
    rep(x, 4)
    {
      if (!ok(mask, 0, x)) uf.unite(16, to(0, x));
      if (!ok(mask, 3, x)) uf.unite(16, to(3, x));
    }

    if (uf.root_num == 2)
    {
      bool t = true;
      rep(y, 4)
      rep(x, 4)
      {
        if (mp[y][x] == 1)
        {
          t &= (!uf.same(16, to(y, x)));
        }
      }
      ans += t;
    }
  }
  show(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}
