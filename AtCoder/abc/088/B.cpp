#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()

using namespace std;
using ll = long long;

const double PI = 3.14159265358979;

void solve()
{
  ll n;
  cin >> n;
  vector<ll> a(n);
  for(int i = 0; i < n; ++i)
  {
    cin >> a[i];
  }

  sort(RALL(a));
  ll ans = 0;
  ll sign = 1;
  for(int i = 0; i < n; ++i)
  {
    ans += a[i] * sign;
    sign = -sign;
  }
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}