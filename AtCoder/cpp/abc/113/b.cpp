#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
  int n, t, a, h;
  cin >> n >> t >> a;
  int ans = 0;
  double ans_t = 1e9;
  for(int i = 0; i < n; ++i)
  {
    cin >> h;
    double temp = abs(a - (t - h * 0.006));
    if (temp < ans_t)
    {
      ans_t = temp;
      ans = i + 1;
    }
  }
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}