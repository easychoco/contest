#include <bits/stdc++.h>
#include <atcoder/all>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i=a;i<(ll)n;++i)
#define repe(i,n) repie(i,0,n)
#define repie(i,a,n) for(ll i=a;i<=(ll)n;++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()

using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<ll, ll>;
void YN(bool a) { cout << (a ? "Yes" : "No") << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
void show(){ cout << endl; }
template <class Head, class... Tail>
void show(Head&& head, Tail&&... tail){ cout << head << " "; show(std::forward<Tail>(tail)...); }
template<class T> inline void showall(T& a) { for(auto v:a) cout<<v<<" "; cout<<endl; }

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
  // グループごとに頂点をまとめる: O(N log N)
  map<int, vector<int>> groups(){
    map<int, vector<int>> ret;
    rep(i, p.size()) ret[root(i)].emplace_back(i);
    return ret;
  }
  //xが属すグループのサイズ
  int size(int x){ return rank[root(x)]; }
  bool same(int x, int y){ return (root(x) == root(y)); }
};

using mint = modint1000000007;

void solve()
{
  ll n;
  cin >> n;
  UnionFind uf (n);
  vector<P> p;
  
  rep(y, n) rep(x, n)
  {
    ll a;
    cin >> a;
    if (y <= x) continue;
    if (a == 1)
    {
      if (uf.same(x, y))
      {
        show(0);
        return;
      }
      uf.unite(x, y);
    }
    if (a == -1) p.emplace_back(x, y);
  }

  vector< vector<ll> > graph(n, vector<ll>(n, 0));
  for(auto pp : p)
  {
    ll n1, n2;
    tie(n1, n2) = pp;
    n1 = uf.root(n1);
    n2 = uf.root(n2);
    graph[n1][n2]++;
    graph[n2][n1]++;
  }

  mint ans = 1;
  ll cnt = 0;
  rep(y, n) rep(x, n)
  {
    if (graph[y][x] > 0) cnt++;
  }
  if (cnt == 0) ans = 0;

  rep(y, n) rep(x, n)
  {
    if (y <= x) continue;
    if (graph[y][x] > 0) ans *= graph[y][x];
  }

  show(ans.val());
}

int main()
{
  fastio;
  solve();

  return 0;
}