// https://atcoder.jp/contests/aising2019/tasks/aising2019_c
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
  bool unite(int x, int y){
    x = root(x); y = root(y);
    if(x == y) return false;
    if(rank[x] > rank[y]) swap(x, y); // rankの小さいものを下につける
    rank[y] += rank[x];
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
  map<int, vector<int>> groups(){
    map<int, vector<int>> ret;
    rep(i, p.size()) ret[root(i)].emplace_back(i);
    return ret;
  }
  //xが属すグループのサイズ
  int size(int x){ return rank[root(x)]; }
  bool same(int x, int y){ return (root(x) == root(y)); }
};

void solve()
{
  ll h, w;
  cin >> h >> w;
  vector<string> mp(h);
  rep(i, h) cin >> mp[i];

  const ll dx[4] = { 0, -1, 0, 1 };
  const ll dy[4] = { -1, 0, 1, 0 };

  UnionFind uf(h * w);

  rep(y, h)
  {
    rep(x, w)
    {
      rep(i, 4)
      {
        ll ny = y + dy[i];
        ll nx = x + dx[i];
        if (ny < 0 || h <= ny) continue;
        if (nx < 0 || w <= nx) continue;
        if (mp[y][x] != mp[ny][nx])
        {
          ll now = y * w + x;
          ll next = ny * w  + nx;
          uf.unite(now, next);
        }
      }
    }
  }
  
  ll ans = 0;
  for (auto map: uf.groups())
  {
    ll b = 0;
    ll wh = 0;
    for (auto num: map.second)
    {
      ll y = num / w;
      ll x = num % w;
      if (mp[y][x] == '#') b++;
      if (mp[y][x] == '.') wh++;
    }
    ans += b * wh;
  }

  show(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}