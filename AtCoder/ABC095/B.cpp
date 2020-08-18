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
  int n, x, m, vmin = 1e9;
  cin >> n >> x;
  int sum = 0;
  for(int i = 0; i < n; ++i)
  {
    cin >> m;
    sum += m;
    vmin = min(vmin, m);
  }
  cout << n + (x - sum) / vmin;
}

int main()
{
  fastio;
  solve();

  return 0;
}