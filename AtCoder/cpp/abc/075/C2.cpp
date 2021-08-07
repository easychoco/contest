#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()

using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve()
{
  ll n, m, a, b;
  cin >> n >> m;
  vector<P> input(m);
  vector< vector<int> > edge(n, vector<int>());
  for(int i = 0; i < m; ++i)
  {
    cin >> a >> b;
    a--; b--;
    input[i] = P(a, b);
    edge[a].emplace_back(b);
    edge[b].emplace_back(a);
  }

  int ans = 0;
  for(int removed = 0; removed < m; ++removed)
  {
    vector<bool> visited(n, false);
    queue<int> que;
    que.push(0);
    while(!que.empty())
    {
      int now = que.front();
      que.pop();
      visited[now] = true;
      for(const auto& to : edge[now])
      {
        if (input[removed].first == now && input[removed].second == to ) continue;
        if (input[removed].first == to  && input[removed].second == now) continue;
        if (!visited[to]) que.push(to);
      }
    }
    bool ok = true;
    for(int i = 0; i < n; ++i) ok &= visited[i];
    ans += !ok;
  }
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}