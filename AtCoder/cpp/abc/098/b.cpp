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
  int n;
  string s;
  cin >> n >> s;
  int ans = 0;
  for(int i = 1; i < n; ++i)
  {
    bool seen_L[26] = {};
    bool seen_R[26] = {};
    for(int l = 0; l < i; ++l)
    {
      seen_L[(int)(s[l] - 'a')] = true;
    }
    for(int r = i; r < n; ++r)
    {
      seen_R[(int)(s[r] - 'a')] = true;
    }
    int score = 0;
    for(int a = 0; a < 26; ++a)
    {
      score += (seen_L[a] & seen_R[a]);
    }
    ans = max(ans, score);
  }
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}