#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()

using namespace std;
using ll = long long;
using P = pair<int, int>;

const double PI = 3.14159265358979;

int dist[8][8];

struct Edge{ ll cost, to; };
void solve()
{
  int n, m, r;
  cin >> n >> m >> r;
  vector<int> ri(r);
  for(int i = 0; i < r; ++i)
  {
    cin >> ri[i];
    ri[i]--;
  }

  int a, b, c;
  vector< vector<Edge> > G(n, vector<Edge>());
  for(int i = 0; i < m; ++i)
  {
    cin >> a >> b >> c;
    a--; b--;
    G[a].emplace_back(Edge{c, b});
    G[b].emplace_back(Edge{c, a});
  }

  const ll INF = 1LL << 60;
  priority_queue<P, vector<P>, greater<P>> que;
  for(int i = 0; i < r; ++i)
  {
    vector<ll> d(n, INF);
    d[ri[i]] = 0;
    que.push(P(0, ri[i])); // P(cost, start)
    while (!que.empty())
    {
      P p = que.top();
      que.pop();
      ll node = p.second;
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
    for(int j = 0; j < r; ++j)
    {
      dist[i][j] = d[ri[j]];
    }
  }

  vector<int> indices(r);
  for(int i = 0; i < r; ++i) indices[i] = i;

  ll ans = INF;
  do {
    ll distance = 0;
    for(int i = 0; i < r - 1; ++i) distance += dist[indices[i]][indices[i + 1]];
    ans = min(ans, distance);
  } while(next_permutation(ALL(indices)));
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}