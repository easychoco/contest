// #include <bits/stdc++.h>
#include <iostream>
#include <cmath>

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
  cout << a + b + c + max({a, b, c}) * (pow(2, k) - 1);
}

int main()
{
  fastio;
  solve();

  return 0;
}