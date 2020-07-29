#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
  int a1, a2, a3;
  cin >> a1 >> a2 >> a3;
  cout << max({a1, a2, a3}) - min({a1, a2, a3});
}

int main()
{
  fastio;
  solve();

  return 0;
}