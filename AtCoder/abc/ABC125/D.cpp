#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
  int n;
  cin >> n;
  vector<int> a(n);
  int min_abs = 1000000007;
  int min_abs_i;
  for(int i = 0; i < n; ++i)
  {
    cin >> a[i];
    if(abs(a[i]) < min_abs)
    {
      min_abs = abs(a[i]);
      min_abs_i = i;
    }
  }

  ll ans = 0;
  for(int i = 0; i < min_abs_i; ++i)
  {
    if (a[i] < 0)
    {
      a[i] = -a[i];
      a[i + 1] = -a[i + 1];
    }
    ans += a[i];
  }
  for(int i = n - 1; i > min_abs_i; --i)
  {
    if (a[i] < 0)
    {
      a[i] = -a[i];
      a[i - 1] = -a[i - 1];
    }
    ans += a[i];
  }
  ans += a[min_abs_i];
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}