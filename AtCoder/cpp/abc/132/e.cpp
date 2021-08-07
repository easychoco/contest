#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

struct Edge{ ll cost, to; };

void solve()
{
  ll n, m, u, v;
  cin >> n >> m;
  vector< vector<ll> > G(n * 3, vector<ll>());
  for(int i = 0; i < m; ++i)
  {
    cin >> u >> v;
    u--; v--;
    G[u].emplace_back(v + n);
    G[u + n].emplace_back(v + n * 2);
    G[u + n * 2].emplace_back(v);
  }

  ll from, to;
  cin >> from >> to;
  from--; to--;

  const ll INF = 1LL << 60;
  vector<ll> d(n * 3, INF);
  d[from] = 0;
  priority_queue<P, vector<P>, greater<P>> que;
  que.push(P(0, from)); // P(cost, start)
  while (!que.empty())
  {
    P p = que.top();
    que.pop();
    ll node = p.second;
    if (d[node] < p.first) continue;
    for (const auto& edge : G[node])
    {
      if (d[edge] > d[node] + 1)
      {
        d[edge] = d[node] + 1;
        que.push(P(d[edge], edge));
      }
    }
  }

  ll dist = d[to];
  cout << (((dist == INF) || (dist % 3 > 1)) ? -1LL : dist / 3);
}

int main()
{
  fastio;
  solve();

  return 0;
}