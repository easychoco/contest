#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ALL(a) (a).begin(),(a).end()

#define X second
#define Y first

using namespace std;
using ll = long long;
using P = pair<int, int>;

const double PI = 3.14159265358979;

int cost[52][52];

void solve()
{
  int h, w;
  cin >> h >> w;

  int road_num = 0;
  vector<string> mp(h);
  for(int i = 0; i < h; ++i)
  {
    cin >> mp[i];
    for(const auto& c : mp[i])
    {
      if (c == '.') road_num++;
    }
  }
  
  queue<P> que;
  que.push(P(0, 0));
  cost[0][0] = 1;

  int dx[4] = {0, 1, 0, -1};
  int dy[4] = {1, 0, -1, 0};
  while(!que.empty())
  {
    P now = que.front();
    que.pop();
    int now_cost = cost[now.Y][now.X];
    for(int i = 0; i < 4; ++i)
    {
      P next = P(now.Y + dy[i], now.X + dx[i]);
      if (next.Y < 0 || h <= next.Y || next.X < 0 || w <= next.X) continue;
      if (mp[next.Y][next.X] == '#' || cost[next.Y][next.X] > 0) continue;

      cost[next.Y][next.X] = now_cost + 1;
      que.push(next);
    }
  }
  if  (cost[h - 1][w - 1] == 0) cout << -1;
  else cout << road_num - cost[h - 1][w - 1];
}

int main()
{
  fastio;
  solve();

  return 0;
}