#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll = long long;

const double PI = 3.14159265358979;

void solve()
{
  int n, t, x, y;
  cin >> n;
  int nt = 0, nx = 0, ny = 0;
  for(int i = 0; i < n; ++i)
  {
    cin >> t >> x >> y;

    int dt = t - nt;
    int dd = abs(x - nx) + abs(y - ny);
    if (dt < dd || ((dt - dd) & 1))
    {
      cout << "No";
      return;
    }
    nt = t;
    nx = x;
    ny = y;
  }
  cout << "Yes";
}

int main()
{
  fastio;
  solve();

  return 0;
}