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
  int len = 0;
  int ans = 0;
  for(int i = 0; i < s.length(); ++i)
  {
    if (s[i] == 'A') len++;
    else if (s[i] == 'C') len++;
    else if (s[i] == 'G') len++;
    else if (s[i] == 'T') len++;
    else len = 0;

    ans = max(ans, len);
  }
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}