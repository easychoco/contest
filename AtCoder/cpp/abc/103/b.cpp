#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
  string s, t;
  cin >> s >> t;

  for(int d = 0; d < s.length(); ++d)
  {
    if (s[0] != t[d]) continue;
    bool ok = true;
    for(int i = 0; i < s.length(); ++i)
    {
      ok &= (s[i] == t[(i + d) % s.length()]);
    }
    if (ok)
    {
      cout << "Yes";
      return;
    }
  }
  cout << "No";
}

int main()
{
  fastio;
  solve();

  return 0;
}