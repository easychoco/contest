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
    // -> x <= y
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

void solve()
{
  ll n, q, t, q1, q2;
  cin >> n >> q;

  vector<ll> cls(n);
  vector< map<ll, ll> > score(n, map<ll, ll>());

  rep(i, n) cin >> cls[i];
  rep(i, n) score[i][--cls[i]] = 1;

  UnionFind uf(n);
  rep(qi, q)
  {
    cin >> t >> q1 >> q2;
    q1--; q2--;
    if (t == 1)
    {
      if (uf.same(q1, q2)) continue;
      if (uf.size(q1) > uf.size(q2)) swap(q1, q2);

      // q1をq2にくっつける
      ll root1 = uf.root(q1);
      ll root2 = uf.root(q2);
      for(const auto& mp : score[root1])
      {
        score[root2][mp.first] += mp.second;
      }

      uf.unite(q1, q2);
    }
    else if (t == 2)
    {
      cout << score[uf.root(q1)][q2] << endl;
    }
  }  
}

int main()
{
  fastio;
  solve();

  return 0;
}