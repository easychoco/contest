#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll = long long;

const double PI = 3.14159265358979;

void solve()
{
  string s, t;
  cin >> s >> t;
  int ls = s.length();
  int lt = t.length();
  int ans = 0;
  for(int i = 0; i <= ls - lt; ++i)
  {
    int score = 0;
    for(int j = 0; j < lt; ++j)
    {
      if (s[i + j] == t[j]) score++;
    }
    ans = max(ans, score);
  }
  cout << lt - ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}