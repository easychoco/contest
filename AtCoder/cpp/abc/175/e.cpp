#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

// score[行][列][行内での個数]
ll dp[3010][3010][4];
ll value[3010][3010];

void solve()
{
  ll Row, Col, k, r, c, v;
  cin >> Row >> Col >> k;
  for(ll i = 0; i < k; ++i)
  {
    cin >> r >> c >> v;
    r--; c--;
    value[r][c] = v;
  }

  for(int i = 0; i < Row; ++i)
    for(int j = 0; j < Col; ++j)
      for(int k = 0; k < 4; ++k)
        dp[i][j][k] = -10;

  dp[0][0][0] = 0;
  for(int i = 0; i < Row; ++i)
  {
    for(int j = 0; j < Col; ++j)
    {
      if (dp[i][j][2] >= 0) dp[i][j][3] = max(dp[i][j][3], dp[i][j][2] + value[i][j]);
      if (dp[i][j][1] >= 0) dp[i][j][2] = max(dp[i][j][2], dp[i][j][1] + value[i][j]);
      if (dp[i][j][0] >= 0) dp[i][j][1] = max(dp[i][j][1], dp[i][j][0] + value[i][j]);

      for(int k = 0; k < 4; ++k)
      {
        if(dp[i][j][k] >= 0)
        {
          if (i + 1 < Row)
          {
            dp[i + 1][j][0] = max(dp[i + 1][j][0], dp[i][j][k]);
          }
          if (j + 1 < Col)
          {
            dp[i][j + 1][k] = max(dp[i][j + 1][k], dp[i][j][k]);
          }
        }
      }
    }
  }
  
  cout << max({
    dp[Row - 1][Col - 1][0], 
    dp[Row - 1][Col - 1][1], 
    dp[Row - 1][Col - 1][2], 
    dp[Row - 1][Col - 1][3]
  });
}

int main()
{
  fastio;
  solve();

  return 0;
}