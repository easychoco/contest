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
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  for(int i = 0; i < h; ++i)
  {
    cin >> s[i];
  }

  vector< vector<int> > ans(h, vector<int>(w, 0));
  for(int j = 0; j < h; ++j)
  {
    for(int i = 0; i < w; ++i)
    {
      if (s[j][i] == '#')
      {
        ans[j][i] = -1;
        for(int y = -1; y <= 1; ++y)
        for(int x = -1; x <= 1; ++x)
        {
          if (j + y < 0 || h <= j + y) continue;
          if (i + x < 0 || w <= i + x) continue;
          if (s[j + y][i + x] == '#') continue;
          ans[j + y][i + x]++;
        }
      }
    }
  }


  for(int j = 0; j < h; ++j)
  {
    for(int i = 0; i < w; ++i)
    {
      cout << (char)(ans[j][i] == -1 ? '#' : ans[j][i] + '0');
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