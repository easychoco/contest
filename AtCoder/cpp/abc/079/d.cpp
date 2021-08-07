#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll = long long;

const double PI = 3.14159265358979;

void solve()
{
  int h, w;
  cin >> h >> w;
  int d[10][10];
  for(int i = 0; i < 10; ++i) for(int j = 0; j < 10; ++j)
  {
    cin >> d[i][j];
  }

  for (int k = 0; k < 10; k++){       // 経由する頂点
    for (int i = 0; i < 10; i++) {		// 始点
      for (int j = 0; j < 10; j++) {	// 終点
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }

  int num;
  ll ans = 0;
  for(int i = 0; i < h; ++i) for(int j = 0; j < w; ++j)
  {
    cin >> num;
    num = abs(num);
    ans += d[num][1];
  }
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}