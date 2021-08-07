#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i = a;i < (ll)n;++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define SHOW(str,val) cout<<(str)<<" : "<<(val)<<endl;

using namespace std;
using ll = long long;
using P = pair<ll, ll>;
// using P = pair<int, int>;
void YN(bool a) { cout << (a ? "Yes" : "No"); }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true;} return false;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true;} return false;}

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
  ll n, m, c, d;
  cin >> n >> m;
  vector<ll> a(n), b(n);
  map<ll, ll> sz_a, sz_b;
  UnionFind uf (n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];
  if (accumulate(ALL(a), 0LL) != accumulate(ALL(b), 0LL) )
  {
    cout << "No";
    return;
  }

  rep(i, m)
  {
    cin >> c >> d;
    c--; d--;
    uf.unite(c, d);
  }

  rep(i, n) 
  {
    sz_a[uf.root(i)] += a[i];
    sz_b[uf.root(i)] += b[i];
  }

  bool ok = true;
  for(const auto& m : sz_a)
  {
    ok &= (sz_a[m.first] == sz_b[m.first]);
  }
  YN(ok);
}

int main()
{
  fastio;
  solve();

  return 0;
}