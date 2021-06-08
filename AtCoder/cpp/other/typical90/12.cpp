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

ll h, w, q;
ll toSeq(ll y, ll x)
{
  if (y < 0 || x < 0) return -10;
  if (y >= h || x >= w) return -10;
  return y * w + x;
}

void solve()
{
  const ll dy[4] = { 0, -1,  0, 1 };
  const ll dx[4] = { 1,  0, -1, 0 };

  cin >> h >> w >> q;
  vector< vector<bool> > mp(h, vector<bool>(w, false));
  UnionFind uf(h * w);
  rep(_, q)
  {
    ll t;
    cin >> t;
    if (t == 1)
    {
      ll r, c;
      cin >> r >> c;
      r--; c--;
      mp[r][c] = true;
      ll now = toSeq(r, c);
      rep(i, 4)
      {
        ll ny = r + dy[i];
        ll nx = c + dx[i];
        ll next = toSeq(ny, nx);
        if (next >= 0 && mp[ny][nx]) uf.unite(now, next);
      }
    }
    else if (t == 2)
    {
      ll ra, ca, rb, cb;
      cin >> ra >> ca >> rb >> cb;
      ra--; ca--; rb--; cb--;
      YN(mp[ra][ca] && mp[rb][cb] && uf.same(toSeq(ra, ca), toSeq(rb, cb)));
    }
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}