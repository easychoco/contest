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
  int a, b, x;
  cin >> a >> b >> x;
  cout << ((a + b >= x && x >= a) ? "YES" : "NO");
}

int main()
{
  fastio;
  solve();

  return 0;
}