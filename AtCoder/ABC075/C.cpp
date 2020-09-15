#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()

using namespace std;
using ll = long long;
using P = pair<int, int>;

class UnionFind{
public:
  vector<int> p;		// 親
  vector<int> rank;	// サイズ・各集合の根のみ有効
  UnionFind(int n){
    p.resize(n, -1);
    rank.resize(n, 1);
  }
  int root(int x){
    if(p[x] == -1)return x;
    else return p[x] = root(p[x]); // 深さを 1 にしている
  }
  void unite(int x, int y){
    x = root(x); y = root(y);
    if(x == y)return;
    if(rank[x] > rank[y]) swap(x, y); // rankの小さいものを下につける
    rank[y] += rank[x];
    p[x] = y;
  }
  //xが属すグループのサイズ
  int size(int x){ return rank[root(x)]; }
  bool same(int x, int y){ return (root(x) == root(y)); }
};

void solve()
{
  ll n, m, a, b;
  cin >> n >> m;
  vector<P> edge(m);
  for(int i = 0; i < m; ++i)
  {
    cin >> a >> b;
    a--; b--;
    edge[i] = P(a, b);
  }

  int ans = 0;
  for(int removed = 0; removed < m; ++removed)
  {
    UnionFind uf(n);
    for(int i = 0; i < m; ++i)
    {
      if (i == removed) continue;
      uf.unite(edge[i].first, edge[i].second);
    }
    if (uf.size(0) < n) ans++;
  }
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}