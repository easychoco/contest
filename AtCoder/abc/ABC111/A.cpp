#include <bits/stdc++.h>

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
  for(int i = 0; i < 3; ++i)
  {
    if (s[i] == '1') cout<< '9';
    if (s[i] == '9') cout<< '1';
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}