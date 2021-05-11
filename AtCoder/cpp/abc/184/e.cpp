#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i=a;i<(ll)n;++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define Show(val) cout<<(val)<<" "
#define Showln(val) cout<<(val)<<endl

using namespace std;
using ll = long long;
using P = pair<ll, ll>;
// using P = pair<int, int>;
void YN(bool a) { cout << (a ? "Yes" : "No"); }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

#define Y first
#define X second

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
ll cost[2010][2010];
bool seen[2010][2010];
bool seena[26];

void solve()
{
  ll h, w;
  cin >> h >> w;

  vector<string> mp(h);
  rep(i, h) cin >> mp[i];

  ll sx, sy, gx, gy;
  vector< vector<P> > warp(26, vector<P>());
  
  rep(i, 26) seena[i] = false;
  rep(y, h) rep(x, w)
  {
    cost[y][x] = 1LL<<60;
    seen[y][x] = false;
    if (mp[y][x] == '#') continue;
    if (mp[y][x] == '.') continue;

    if (mp[y][x] == 'G')
    {
      gx = x; gy = y;
    }
    else if (mp[y][x] == 'S')
    {
      sx = x; sy = y;
    }
    else
    {
      int idx = (mp[y][x] - 'a');
      warp[idx].emplace_back(P(y, x));
    }
  }

  // tuple<cost, y, x>
  queue<tuple<int, int, int>> que;
  que.emplace(0, sy, sx);
  while(!que.empty())
  {
    ll path;
    int y, x;
    tie(path, y, x) = que.front();
    que.pop();

    if (seen[y][x]) continue;
    seen[y][x] = true;
    if (mp[y][x] == 'G') break;

    if (mp[y][x] != 'S' && isalpha(mp[y][x]))
    {
      int idx = (mp[y][x] - 'a');
      if (!seena[idx])
      for(const auto& p : warp[idx])
      {
        int ny = p.Y;
        int nx = p.X;
        if (seen[ny][nx]) continue;
        if (chmin(cost[ny][nx], path + 1))
        {
          que.emplace(path + 1, ny, nx);
        }
      }
      seena[idx] = true;
    }

    rep(ii, 4)
    {
      int ny = y + dy[ii];
      int nx = x + dx[ii];
      if (ny < 0 || h <= ny) continue;
      if (nx < 0 || w <= nx) continue;

      if (mp[ny][nx] == '#') continue;
      if (seen[ny][nx]) continue;
      if (chmin(cost[ny][nx], path + 1))
      {
        que.emplace(path + 1, ny, nx);
      }
    }
  }
  if (cost[gy][gx] == 1LL<<60) cost[gy][gx] = -1;
  cout << cost[gy][gx] << endl;
}

int main()
{
  fastio;
  solve();

  return 0;
}