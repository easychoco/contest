#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;
const ll INF = 1LL << 60;

struct Edge{ ll cost, to; };

void solve()
{
	ll n, u, v, w;
  cin >> n;
  vector< vector<Edge> > G(n, vector<Edge>());
  for(int i = 0; i < n - 1; ++i)
  {
    cin >> u >> v >> w;
    u--; v--;
    G[u].emplace_back(Edge{w, v});
    G[v].emplace_back(Edge{w, u});
  }

  vector<ll> d(n, INF);
  d[0] = 0;
  priority_queue<P, vector<P>, greater<P>> que;
  que.push(P(0, 0));
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

  for(int i = 0; i < n; ++i)
  {
    cout << (d[i] & 1) << endl;
  }
}

int main()
{
	fastio;
	solve();

	return 0;
}