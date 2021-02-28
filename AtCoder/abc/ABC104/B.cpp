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
  bool ok = (s[0] == 'A');
  int cnt = 0;
  for(int i = 1; i < s.length(); ++i)
  {
    if (s[i] == 'C') cnt += ((2 <= i && i <= s.length() - 2) ? 1 : 2);
    else ok &= ((int)'a' <= (int)s[i] && (int)s[i] <= (int)'z');
  }
  ok &= (cnt == 1);
  cout << (ok ? "AC" : "WA");
}

int main()
{
  fastio;
  solve();

  return 0;
}