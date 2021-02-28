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

// 100 は 上 / 101 は 下
ll dist2rsq[102][102];

void solve()
{
  ll n, xi, yi;
  cin >> n;
  // tuple<x, y>
  vector<tuple<ll, ll>> pos(n);
  // tuple<dist, idx, idx>
  vector<tuple<double, ll, ll>> dist;
  rep(i, n)
  {
    cin >> xi >> yi;
    pos[i] = make_tuple(xi, yi);
  }

  rep(i, n-1) repi(j, i+1, n)
  {
    ll x1, y1, x2, y2;
    tie(x1, y1) = pos[i];
    tie(x2, y2) = pos[j];
    double _2r = hypot(x1 - x2, y1 - y2);
    dist.emplace_back(_2r, i, j);
  }

  rep(i, n)
  {
    // n:100 は 上 / n+1:101 は 下
    dist.emplace_back(100 - get<1>(pos[i]), i, n);
    dist.emplace_back(100 + get<1>(pos[i]), i, n+1);
  }

  sort(ALL(dist));

  double ac = 0.0, wa = 300.0;
  while(wa - ac > 0.00005)
  {
    double wj = (ac + wa) / 2.0;
    UnionFind uf(n + 2);
    for(const auto& d : dist)
    {
      double _2r; 
      ll i, j;
      tie(_2r, i, j) = d;
      if (_2r < wj) uf.unite(i, j);
      else break;
    }

    if ( uf.same(n, n+1) ) wa = wj;
    else ac = wj;
  }

  printf("%.5lf\n", ac / 2.0);
}

int main()
{
  fastio;
  solve();

  return 0;
}