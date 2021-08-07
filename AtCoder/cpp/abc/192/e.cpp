#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i=a;i<(ll)n;++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()

using namespace std;
using ll = long long;
using P = pair<ll, ll>;
void YN(bool a) { cout << (a ? "Yes" : "No") << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
void show(){ cout << endl; }
template <class Head, class... Tail>
void show(Head&& head, Tail&&... tail){ cout << head << " "; show(std::forward<Tail>(tail)...); }
template<class T> inline void showall(T& a) { for(auto v:a) cout<<v<<" "; cout<<endl; }

struct Edge{ ll cost, to, k; };
void solve()
{
  ll n, m, x, y;
  cin >> n >> m >> x >> y;
  
  x--; y--;
  vector< vector<Edge> > G(n, vector<Edge>());
  for(int i = 0; i < m; ++i)
  {
    ll a, b, t, k;
    cin >> a >> b >> t >> k;
    a--; b--;
    G[a].emplace_back(Edge{t, b, k});
    G[b].emplace_back(Edge{t, a, k}); // 無向グラフの場合
  }

  const ll INF = 1LL << 60;
  vector<ll> d(n, INF);
  d[x] = 0;
  priority_queue<P, vector<P>, greater<P>> que;
  que.push(P(0, x)); // P(cost, start)
  while (!que.empty())
  {
    P p = que.top();
    que.pop();
    ll now = p.second;
    if (d[now] < p.first) continue;
    for (const auto& edge : G[now])
    {
      ll nd = (d[now] + edge.k - 1) / edge.k * edge.k;
      if (d[edge.to] > nd + edge.cost)
      {
        d[edge.to] = nd + edge.cost;
        que.push(P(d[edge.to], edge.to));
      }
    }
  }

  show(d[y] == INF ? -1 : d[y]);
}

int main()
{
  fastio;
  solve();

  return 0;
}