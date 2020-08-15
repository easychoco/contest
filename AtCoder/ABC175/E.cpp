#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

// score[行][列][行内での個数]
ll score[3010][3010][3];
ll value[3010][3010];


void solve()
{
  ll r, c, k, inr, inc, inv;
  cin >> r >> c >> k;
  for(ll i = 0; i < k; ++i)
  {
    cin >> inr >> inc >> inv;
    value[inr][inc] = inv;
  }

  for(ll row = 1; row <= r; ++row)
  {
    for(ll col = 1; col <= c; ++col)
    {
      score[row][col][0] = max(score[row][col - 1][0], 
        max({
          score[row - 1][col][0],
          score[row - 1][col][1],
          score[row - 1][col][2]
        })
        + value[row][col]
      );
      score[row][col][1] = max(score[row][col][1], score[row][col - 1][0] + value[row][col]);
      score[row][col][2] = max(score[row][col][2], score[row][col - 1][1] + value[row][col]);
      // cout << row << " " << col << " " << score[row][col][0] << endl;
    }
  }

  cout << max( { score[r][c][0], score[r][c][1], score[r][c][2] } );
}

int main()
{
  fastio;
  solve();

  return 0;
}