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
  vector<ll> a1(n);
  vector<ll> a2(n);
  for(int i = 0; i < n; ++i) cin >> a1[i];
  for(int i = 0; i < n; ++i) cin >> a2[i];

  reverse(ALL(a2));
  for(int i = 0; i < n - 1; ++i)
  {
    a1[i + 1] += a1[i];
    a2[i + 1] += a2[i];
  }
  reverse(ALL(a2));
  ll ans = 0;

  for(int i = 0; i < n; ++i)
  {
    ans = max(ans, a1[i] + a2[i]);
  }
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}