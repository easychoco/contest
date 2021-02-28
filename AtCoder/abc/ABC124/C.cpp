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
  int len = s.length();
  string s01 = "";
  string s10 = "";
  for(int i = 0; i < len / 2; ++i)
  {
    s01 += "01";
    s10 += "10";
  }
  if (len & 1)
  {
    s01 += "0";
    s10 += "1";
  }

  int dist01 = 0;
  int dist10 = 0;
  for(int i = 0; i < len; ++i)
  {
    if (s[i] == s01[i]) dist01++;
    if (s[i] == s10[i]) dist10++;
  }
  cout << min(dist01, dist10);
}

int main()
{
  fastio;
  solve();

  return 0;
}