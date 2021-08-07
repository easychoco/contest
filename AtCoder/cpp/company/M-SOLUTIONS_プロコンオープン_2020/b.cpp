#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
  int a, b, c, k;
  cin >> a >> b >> c >> k;
  int cnt = 0;
  while(a >= b)
  {
    b *= 2;
    cnt++;
  }
  while(b >= c)
  {
    c *= 2;
    cnt++;
  }
  cout << (cnt <= k ? "Yes" : "No");
}

int main()
{
  fastio;
  solve();

  return 0;
}