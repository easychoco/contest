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

  reverse(s.begin(), s.end());
  vector<int> mods(s.length(), 0);
  mods[0] = s[0] - '0';
  int digit = 10;
  for(int i = 1; i < s.length(); ++i)
  {
    mods[i] = (mods[i - 1] + (s[i] - '0') * digit) % 2019;
    digit *= 10;
    digit %= 2019;
  }
  vector<int> mp(2020, 0);
  mp[0]++;
  for(const auto& v : mods)
  {
    mp[v]++;
  }

  ll ans = 0;
  for(const auto& v : mp)
  {
    ans += v * (v - 1) / 2;
  }
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}