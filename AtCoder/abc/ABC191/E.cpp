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

struct Edge{ ll cost, to; };
void solve()
{
  ll n, m, u, v, w;
  cin >> n >> m;
  vector< vector<Edge> > G(n, vector<Edge>());
  for(int i = 0; i < m; ++i)
  {
    cin >> u >> v >> w;
    u--; v--;
    G[u].emplace_back(Edge{w, v});
  }

  const ll INF = 1LL << 60;
  vector<ll> ans(n, INF);
  rep(start, n)
  {
    vector<ll> d(n, INF);
    d[start] = 0;
    priority_queue<P, vector<P>, greater<P>> que;
    que.push(P(0, start)); // P(cost, start)
    while (!que.empty())
    {
      P p = que.top();
      que.pop();
      ll node = p.second;
      for (const auto& edge : G[node])
      {
        if (edge.to == start) chmin(ans[start], d[node] + edge.cost);
      }

      if (d[node] < p.first) continue;
      for (const auto& edge : G[node])
      {
        if (d[edge.to] > d[node] + edge.cost)
        {
          d[edge.to] = d[node] + edge.cost;
          que.push(P(d[edge.to], edge.to));
        }
      }
    }
  }

  rep(i, n)
  {
    if (ans[i] == INF) ans[i] = -1;
    Showln(ans[i]);
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}