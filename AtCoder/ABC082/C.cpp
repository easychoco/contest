#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll = long long;

const double PI = 3.14159265358979;

void solve()
{
  ll n, a;
  cin >> n;
  map<ll, ll> mp;
  for(int i = 0; i < n; ++i)
  {
    cin >> a;
    mp[a]++;
  }
  ll ans = 0;
  for(const auto& m : mp)
  {
    ans += (m.first > m.second ? m.second : m.second - m.first);
  }
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}