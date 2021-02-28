#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
  ll a, b;
  cin >> a >> b;

  a = max(0LL, a - 1);
  if      (a % 4 == 0);
  else if (a % 4 == 1) a = 1;
  else if (a % 4 == 2) a += 1;
  else if (a % 4 == 3) a = 0;

  if      (b % 4 == 0);
  else if (b % 4 == 1) b = 1;
  else if (b % 4 == 2) b += 1;
  else if (b % 4 == 3) b = 0;

  cout << (a ^ b);
}

int main()
{
  fastio;
  solve();

  return 0;
}