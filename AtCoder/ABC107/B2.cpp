#include <bits/stdc++.h>

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
  vector<string> a(h);
  for(int i = 0; i < h; ++i)
  {
    cin >> a[i];
  }

  vector<bool> col(w, false);
  vector<bool> row(h, false);
  for(int i = 0; i < h; ++i)
  {
    for(int j = 0; j < w; ++j)
    {
      if (a[i][j] == '#')
      {
        row[i] = true;
        col[j] = true;
      }
    }
  }

  for(int i = 0; i < h; ++i)
  {
    if (!row[i]) continue;
    for(int j = 0; j < w; ++j)
    {
      if (col[j]) cout << a[i][j];
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