// #include <bits/stdc++.h>
#include <iostream>
#include <string>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
  string s;
  cin >> s;
  int ans = 700;
  ans += (s[0] == 'o') * 100;
  ans += (s[1] == 'o') * 100;
  ans += (s[2] == 'o') * 100;
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}