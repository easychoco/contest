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
  int p_count = 0;
  for(int i = 0; i < s.length(); ++i) p_count += s[i] == '1';
  cout << min(p_count, (int)s.length() - p_count) * 2;
}

int main()
{
  fastio;
  solve();

  return 0;
}