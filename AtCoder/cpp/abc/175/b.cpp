#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
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

  sort(a.begin(), a.end());

  int ans = 0;
  for(int i = 0; i < n - 2; ++i)
  {
    for(int j = i + 1; j < n - 1; ++j)
    {
      if (a[i] == a[j]) continue;
      for(int k = j + 1; k < n; ++k)
      {
        if (a[j] == a[k]) continue;
        if (a[i] + a[j] > a[k]) ans++;
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