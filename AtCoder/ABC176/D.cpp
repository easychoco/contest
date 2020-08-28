#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

int h, w;
int seen[1010][1010];

vector<string> mp;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

void bfs(queue<P> que, int lv)
{
  if (que.empty()) return;
  queue<P> tmp;

  // 歩き
  while(!que.empty())
  {
    P tp = que.front();
    tmp.push(tp);
    que.pop();
    for(int i = 0; i < 4; ++i)
    {
      int ny = tp.first  + dy[i];
      int nx = tp.second + dx[i];

      if (ny < 0 || h <= ny) continue;
      if (nx < 0 || w <= nx) continue;

      if (seen[ny][nx] == 0 && mp[ny][nx] == '.')
      {
        seen[ny][nx] = lv;
        que.push(P(ny, nx));
        tmp.push(P(ny, nx));
      }
    }
  }

  // ワープ
  queue<P> next_que;
  while(!tmp.empty())
  {
    P tp = tmp.front();
    tmp.pop();
    for(int y = -2; y <= 2; ++y)
    {
      int ny = tp.first + y;
      if (ny < 0 || h <= ny) continue;

      for(int x = -2; x <= 2; ++x)
      {
        int nx = tp.second + x;
        if (nx < 0 || w <= nx) continue;

        if (seen[ny][nx] == 0 && mp[ny][nx] == '.')
        {
          seen[ny][nx] = lv + 1;
          next_que.push(P(ny, nx));
        }
      }
    }
  }
  bfs(next_que, lv + 1);
}

void solve()
{
  int cy, cx;
  int dy, dx;

  cin >> h >> w;
  cin >> cy >> cx;
  cin >> dy >> dx;

  mp.resize(h);
  cx--; cy--;
  dx--; dy--;
  for(int i = 0; i < h; ++i)
  {
    cin >> mp[i];
  }

  queue<P> que;
  que.push(P(cy, cx));
  seen[cy][cx] = 1;

  bfs(que, 1);
  cout << seen[dy][dx] - 1;

}

int main()
{
  fastio;
  solve();

  return 0;
}