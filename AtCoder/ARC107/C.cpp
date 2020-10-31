#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i=a;i<(ll)n;++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define Show(val) cout<<(val)<<" "
#define Showln(val) cout<<(val)<<endl

using namespace std;
using ll = long long;
using P = pair<ll, ll>;
// using P = pair<int, int>;
void YN(bool a) { cout << (a ? "Yes" : "No"); }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

// auto mod int
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
// const int mod = 1000000007;
const int mod = 998244353;
struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
  mint operator+(const mint a) const { return mint(*this) += a;}
  mint operator-(const mint a) const { return mint(*this) -= a;}
  mint operator*(const mint a) const { return mint(*this) *= a;}
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const { return pow(mod-2);}
  mint& operator/=(const mint a) { return *this *= a.inv();}
  mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

mint factor(mint a)
{
  if (a.x <= 1) return a;
  return a * factor(a - 1);
}

class UnionFind{
public:
  vector<int> p;		// 親
  vector<int> rank;	// サイズ・各集合の根のみ有効
  UnionFind(int n){
    p.resize(n, -1);
    rank.resize(n, 1);
  }
  int root(int x){
    if(p[x] == -1) return x;
    else return p[x] = root(p[x]); // 深さを 1 にしている
  }
  void unite(int x, int y){
    x = root(x); y = root(y);
    if(x == y)return;
    if(rank[x] > rank[y]) swap(x, y); // rankの小さいものを下につける
    rank[y] += rank[x];
    p[x] = y;
  }
  // グループの数
  ll root_num() {
    ll num = 0;
    for(ll x : p) if (x < 0) num++;
    return num;
  }
  //xが属すグループのサイズ
  int size(int x){ return rank[root(x)]; }
  bool same(int x, int y){ return (root(x) == root(y)); }
};

void solve()
{
  ll n, k;
  cin >> n >> k;
  vector< vector<ll> > a(n, vector<ll>(n));
  rep(i, n) rep(j, n)
  {
    cin >> a[i][j];
  }

  UnionFind uf_col(n), uf_row(n);

  // col: 列, row: 行
  ll col_size = 0;
  ll row_size = 0;

  for(int x = 0; x < n - 1; ++x)
  for(int y = x + 1; y < n; ++y)
  {
    ll sum_max_col = 0;
    rep(i, n) chmax(sum_max_col, a[i][x] + a[i][y]);
    if (sum_max_col <= k) uf_col.unite(x, y);

    ll sum_max_row = 0;
    rep(i, n) chmax(sum_max_row, a[x][i] + a[y][i]);
    if (sum_max_row <= k) uf_row.unite(x, y);
  }

  // ここ高速化できる
  // uf.roots()みたいなので高速化できる
  map<int, int> ufc_roots, ufr_roots;
  rep(i, n)
  {
    ufc_roots[uf_col.root(i)] = uf_col.size(i);
    ufr_roots[uf_row.root(i)] = uf_row.size(i);
  }

  mint cf = 1, rf = 1;
  for(const auto& mp : ufc_roots) cf *= factor(mp.second);
  for(const auto& mp : ufr_roots) rf *= factor(mp.second);

  cout << cf * rf << endl;

}

int main()
{
  fastio;
  solve();

  return 0;
}