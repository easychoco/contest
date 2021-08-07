#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;
// 50min
void solve()
{
  int n, c, c_input;
  cin >> n >> c;
  vector< vector<int> > cost(c, vector<int>(c));
  vector< vector<int> > grid(3, vector<int>(c, 0));

  for(int i = 0; i < c; ++i)
  {
    for(int j = 0; j < c; ++j)
    {
      cin >> cost[i][j];
    }
  }

  for(int i = 1; i <= n; ++i)
  {
    for(int j = 1; j <= n; ++j)
    {
      cin >> c_input;
      c_input--;
      grid[(i + j) % 3][c_input]++;
    }
  }

  ll ans = 1LL << 60;
  for(int c1 = 0; c1 < c; ++c1)
  {
    for(int c2 = 0; c2 < c; ++c2)
    {
      if (c1 == c2) continue;
      for(int c3 = 0; c3 < c; ++c3)
      {
        if (c1 == c3) continue;
        if (c2 == c3) continue;

        ll score = 0;
        for(int i = 0; i < c; ++i)
        {
          score += grid[0][i] * cost[i][c1];
          score += grid[1][i] * cost[i][c2];
          score += grid[2][i] * cost[i][c3];
        }
        ans = min(ans, score);
      }
    }
  }
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}