#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
  int n, k;
  string s;
  cin >> n >> k >> s;
  vector<int> enc(1, 1);
  for(int i = 1; i < n; ++i)
  {
    if (s[i - 1] == s[i]) enc.back()++;
    else enc.emplace_back(1);
  }

  ll ans = 0;
  bool startWithZero = (s[0] == '0');
  int start_i = startWithZero != (k & 1);

  ll sum = 0;
  if (start_i < enc.size()) sum += enc[start_i];
  for(int i = 1; i <= k; ++i)
  {
    if (start_i - i >= 0) sum += enc[start_i - i];
    if (start_i + i < enc.size()) sum += enc[start_i + i];
  }
  ans = max(ans, sum);

  for(int i = start_i + 2; i < enc.size(); i += 2)
  {
    if (i - k - 2 >= 0) sum -= enc[i - k - 2];
    if (i - k - 1 >= 0) sum -= enc[i - k - 1];
    if (i + k - 1 < enc.size()) sum += enc[i + k - 1];
    if (i + k - 0 < enc.size()) sum += enc[i + k];
    ans = max(ans, sum);
  }
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}