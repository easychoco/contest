#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
  ll n, k;
  cin >> n >> k;
  vector<ll> c(n);
  vector<ll> p(n);
  for(int i = 0; i < n; ++i)
  {
    cin >> p[i];
    p[i]--;
  }
  for(int i = 0; i < n; ++i) cin >> c[i];

  ll ans = -1e18;
  for(int i = 0; i < n; ++i)
  {
    int x = i;
    vector<int> s;
    ll total = 0;
    while(true)
    {
      x = p[x];
      s.emplace_back(c[x]);
      total += c[x];
      if (x == i) break;
    }

    ll sz = s.size();
    ll now = 0;
    for(int j = 0; j < sz; ++j)
    {
      now += s[j];
      if (j + 1 > k) break;
      ll score = now;
      if(total > 0)
      {
        score += total * ((k - j - 1) / sz);
      }
      ans = max(ans, score);
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