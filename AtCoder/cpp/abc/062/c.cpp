#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()

using namespace std;
using ll = long long;

const double PI = 3.14159265358979;

void solve()
{
  ll h, w;
  cin >> h >> w;
  ll ans = 1e10;

  for(int i = 0; i < 2; ++i)
  {
    ans = min(ans, (h % 3 > 0) * w);

    // 縦に切る
    for(int x = 1; x < w; ++x)
    {
      ll s1 = x * h;
      ll y = h / 2;
      ll s2 = (w - x) * y;
      ll s3 = (w - x) * (h - y);
      ans = min(ans, max({s1, s2, s3}) - min({s1, s2, s3}));
    }
    swap(h, w);
  }
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}