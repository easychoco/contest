#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define X first
#define Y second

using namespace std;
using ll = long long;
using P = pair<int, int>;

const double PI = 3.14159265358979;

int h, w, n;
int ans[101][101];
vector<int> color;
int now_color;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int x, int y)
{
  if (ans[y][x] != 0) return;
  if (color[now_color] == 0)
  {
    now_color++;    
    return dfs(x, y);
  }

  color[now_color]--;
  ans[y][x] = now_color + 1;

  for(int i = 0; i < 4; ++i)
  {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx < 0 || w <= nx) continue;
    if (ny < 0 || h <= ny) continue;
    dfs(nx, ny);
  }
}

void solve()
{
  cin >> h >> w >> n;
  color = vector<int>(n);
  for(int i = 0; i < n; ++i)
  {
    cin >> color[i];
  }

  dfs(0, 0);
  for(int y = 0; y < h; ++y)
  {
    for(int x = 0; x < w; ++x)
    {
      cout << ans[y][x] << " ";
    }
    cout << endl;
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}
