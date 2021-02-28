#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

int h, w;
int cost[1010][1010];

vector<string> mp;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

void solve()
{
  int sy, sx;
  int gy, gx;

  cin >> h >> w;
  cin >> sy >> sx;
  cin >> gy >> gx;

  mp.resize(h);
  sx--; sy--;
  gx--; gy--;
  for(int i = 0; i < h; ++i)
  {
    cin >> mp[i];
  }

  deque<P> que;
  que.push_front(P(sy, sx));
  cost[sy][sx] = 1;

  while(!que.empty())
  {
    int ty = que.front().first;
    int tx = que.front().second;    
    que.pop_front();
    int dist = cost[ty][tx];

    // 徒歩
    for(int i = 0; i < 4; ++i)
    {
      int ny = ty + dy[i];
      int nx = tx + dx[i];
      if (ny < 0 || h <= ny) continue;
      if (nx < 0 || w <= nx) continue;
      if (mp[ny][nx] == '#') continue;
      if (0 < cost[ny][nx] && cost[ny][nx] <= dist) continue;
      cost[ny][nx] = dist;
      que.push_front(P(ny, nx));
    }

    // 魔法
    for(int y = -2; y <= 2; ++y) for(int x = -2; x <= 2; ++x)
    {
      int ny = ty + y;
      int nx = tx + x;
      if (ny < 0 || h <= ny) continue;
      if (nx < 0 || w <= nx) continue;
      if (mp[ny][nx] == '#') continue;
      if (0 < cost[ny][nx] && cost[ny][nx] <= dist + 1) continue;
      cost[ny][nx] = dist + 1;
      que.push_back(P(ny, nx));
    }
  }
  cout << cost[gy][gx] - 1;

}

int main()
{
  fastio;
  solve();

  return 0;
}