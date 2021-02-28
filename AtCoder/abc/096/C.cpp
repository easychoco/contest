// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
  int h, w;
  cin >> h >> w;
  vector<string> mp(h);
  for(int i = 0; i < w; ++i)
  {
    cin >> mp[i];
  }

  for(int y = 0; y < h; ++y)
  {
    for(int x = 0; x < w; ++x)
    {
      if (mp[y][x] == '#')
      {
        if (y >= 1 && mp[y - 1][x] == '#') continue;
        if (x >= 1 && mp[y][x - 1] == '#') continue;
        if (y + 1 < h && mp[y + 1][x] == '#') continue;
        if (x + 1 < w && mp[y][x + 1] == '#') continue;
        cout << "No";
        return;
      }
    }
  }
  cout << "Yes";
}

int main()
{
  fastio;
  solve();

  return 0;
}