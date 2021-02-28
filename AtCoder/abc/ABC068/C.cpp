#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()

using namespace std;
using ll = long long;
using P = pair<int, int>;

const double PI = 3.14159265358979;

void solve()
{
  int n, m, a, b;
  cin >> n >> m;

  vector< vector<ll> > G(n, vector<ll>(0));
  for(int i = 0; i < m; ++i)
  {
    cin >> a >> b;
    a--; b--;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }

  vector<bool> visited(n, false);
  queue<P> que;

  que.push(P(0, 0));

  while(!que.empty())
  {
    P fr = que.front();
    que.pop();
    
    ll now = fr.first;
    ll depth = fr.second;

    if (depth >= 3) break;

    if (visited[now]) continue;
    visited[now] = true;

    for(const auto& next : G[now])
    {
      que.push(P(next, depth + 1));
    }
  }

  cout << (visited[n - 1] ? "POSSIBLE" : "IMPOSSIBLE");  
}

int main()
{
  fastio;
  solve();

  return 0;
}