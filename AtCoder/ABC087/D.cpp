#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll = long long;
using P = pair<int, int>;

const double PI = 3.14159265358979;

struct Edge{ ll to, cost; };
void solve()
{
  ll n, m, l, r, d;
  cin >> n >> m;
  vector< vector<Edge> > G(n, vector<Edge>());
  for(int i = 0; i < m; ++i)
  {
    cin >> l >> r >> d;
    l--; r--;
    G[l].emplace_back(Edge{r, d});
    G[r].emplace_back(Edge{l, -d});
  }

  const ll INF = 1LL << 60;
  vector<bool> seen(n, false);
  vector<ll> dist(n, INF);
  for(int i = 0; i < n; ++i)
  {
    if (seen[i] == false)
    {
      // BFS(i);
      queue<ll> que;
      que.push(i);
      while(!que.empty())
      {
        int now = que.front();
        que.pop();
        if (seen[now]) continue;
        seen[now] = true;
        for(const auto& e : G[now])
        {
          if (dist[e.to] == INF)
          {
            dist[e.to] = dist[now] + e.cost;
          }
          else if (dist[e.to] != dist[now] + e.cost)
          {
            cout << "No";
            return;
          }
          que.push(e.to);
        }
      }
    }
  }
  cout << "Yes";
}

int main()
{
  fastio;
  solve();

  return 0;
}