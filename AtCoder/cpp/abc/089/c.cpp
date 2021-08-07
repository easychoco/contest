#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll = long long;

const double PI = 3.14159265358979;

void solve()
{
  ll n;
  cin >> n;
  string s;
  vector<ll> p(5);
  for(int i = 0; i < n; ++i)
  {
    cin >> s;
    if (s[0] == 'M') p[0]++;
    if (s[0] == 'A') p[1]++;
    if (s[0] == 'R') p[2]++;
    if (s[0] == 'C') p[3]++;
    if (s[0] == 'H') p[4]++;
  }

  ll ans = 0;
  for(int i1 = 0; i1 < 3; ++i1)
  {
    for(int i2 = i1 + 1; i2 < 4; ++i2)
    {
      for(int i3 = i2 + 1; i3 < 5; ++i3)
      {
        ans += p[i1] * p[i2] * p[i3];
      }
    }
  }
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}