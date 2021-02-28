#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
  int n, a;
  cin >> n;
  int ans = 0;
  for(int i = 0; i < n; ++i)
  {
    cin >> a;
    while(a % 2 == 0)
    {
      a /= 2;
      ans++;
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