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
  ll k;
  cin >> s >> k;
  for(int i = 0; i < k; ++i)
  {
    if (s[i] != '1')
    {
      cout << s[i];
      return;
    }
  }
  cout << s[k - 1];
}

int main()
{
  fastio;
  solve();

  return 0;
}