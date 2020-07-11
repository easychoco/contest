#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
  int n;
  cin >> n;
  vector<int> hist(n + 1, 0);
  for(int x = 1; x*x < n; ++x)
  {
    int x2 = x * x;
    for(int y = 1; y*y < n; ++y)
    {
      int y2 = y * y;
      int xy = x * y;
      if (x2 + y2 + xy > n) break;
      for(int z = 1; z*z < n; ++z)
      {
        int sum = x2 + y2 + z*z + xy + (x + y)*z;
        if (sum > n) break;
        hist[sum]++;
      }
    }
  }
  for(int i = 1; i <= n; ++i)
  {
    cout << hist[i] << endl;
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}