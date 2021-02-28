#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

//1950~2014

void solve()
{
  ll n;
  cin >> n;
  vector<ll> a(n);
  cin >> a[0];

  ll ans = 0;
  ll sum = a[0];
  for(int i = 1; i < n; ++i)
  {
    cin >> a[i];
    if (a[i - 1] < a[i])
    {
      if (a[i - 1] > 0)
      {
        a[i] += sum % 2;
      }
      ans += sum / 2;
      sum = 0;
    }
    sum += a[i];
  }
  cout << ans + sum / 2;
}

int main()
{
  fastio;
  solve();

  return 0;
}