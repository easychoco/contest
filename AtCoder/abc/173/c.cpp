#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
  int h, w, k;
  cin >> h >> w >> k;
  string c[6];
  for(int i = 0; i < h; ++i)
  {
    cin >> c[i];
  }

  int all_blacks = 0;
  vector<int> h_num(h, 0);
  vector<int> w_num(w, 0);
  for(int i = 0; i < h; ++i)
  {
    for(int j = 0; j < w; ++j)
    {
      if (c[i][j] == '#') 
      {
        h_num[i]++;
        all_blacks++;
      }
    }
  }

  for(int i = 0; i < w; ++i)
  {
    for(int j = 0; j < h; ++j)
    {
      if (c[j][i] == '#') w_num[i]++;
    }
  }

  int ans = 0;
  int mask = 1 << (h + w);
  while(mask--, mask >= 0)
  {
    int h_mask = mask >> w;
    int w_mask = (mask & 0b111111);

    int h_hidden_num = 0;
    int w_hidden_num = 0;
    for(int i = 0; i < h; ++i)
    {
      if (( h_mask & (1 << i) ) > 0) h_hidden_num += h_num[i];
    }

    for(int i = 0; i < w; ++i)
    {
      if (( w_mask & (1 << i) ) > 0) w_hidden_num += w_num[i];
    }

    int rest_num = all_blacks - h_hidden_num - w_hidden_num;
    for(int i = 0; i < h; ++i)
    {
      if ( (h_mask & (1 << i) ) == 0) continue;
      for(int j = 0; j < w; ++j)
      {
        if ( (w_mask &  (1 << j) ) == 0) continue;
        rest_num += (c[i][j] == '#');
      }
    }
    ans += (rest_num == k);
  }
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}