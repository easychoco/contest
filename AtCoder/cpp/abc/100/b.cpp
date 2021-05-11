#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
  int d, n;
  cin >> d >> n;
  n += n / 100;
  int ans = pow(100, d) * n;
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}