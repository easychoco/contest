// #include <bits/stdc++.h>
#include <iostream>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
  int n, m, x, a;
  cin >> n >> m >> x;

  int lcost = 0, rcost = 0;
  for(int i = 0; i < m; ++i)
  {
    cin >> a;
    (a < x ? lcost : rcost) += 1;
  }
  cout << min(lcost, rcost);

}

int main()
{
  fastio;
  solve();

  return 0;
}