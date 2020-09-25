// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <utility>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()

using namespace std;
using ll = long long;
using P = pair<int, int>;

const double PI = 3.14159265358979;
struct Edge{ ll cost, to; };


void solve()
{
  ll n, u, v;
  cin >> n;
  vector< vector<Edge> > G(n, vector<Edge>());
  for(int i = 0; i < n - 1; ++i)
  {
    cin >> u >> v;
    u--; v--;
    G[u].emplace_back(Edge{1, v});
    G[v].emplace_back(Edge{1, u});
  }

  const ll INF = 1LL << 60;
  vector<ll> d1(n, INF);
  d1[0] = 0;
  priority_queue<P, vector<P>, greater<P>> que;
  que.push(P(0, 0)); // P(cost, start)
  while (!que.empty())
  {
    P p = que.top();
    que.pop();
    ll node = p.second;
    if (d1[node] < p.first) continue;
    for (const auto& edge : G[node])
    {
        if (d1[edge.to] > d1[node] + edge.cost)
        {
            d1[edge.to] = d1[node] + edge.cost;
            que.push(P(d1[edge.to], edge.to));
        }
    }
  }
  
  vector<ll> dn(n, INF);
  dn[n - 1] = 0;
  que.push(P(0, n - 1)); // P(cost, start)
  while (!que.empty())
  {
    P p = que.top();
    que.pop();
    ll node = p.second;
    if (dn[node] < p.first) continue;
    for (const auto& edge : G[node])
    {
        if (dn[edge.to] > dn[node] + edge.cost)
        {
            dn[edge.to] = dn[node] + edge.cost;
            que.push(P(dn[edge.to], edge.to));
        }
    }
  }

  int n1 = 0;
  for(int i = 0; i < n; ++i)
  {
    n1 += d1[i] <= dn[i];
  }
  cout << (n1 * 2 <= n ? "Snuke" : "Fennec");
}

int main()
{
  fastio;
  solve();

  return 0;
}