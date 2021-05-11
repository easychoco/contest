#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
  ll n, a, max_a = 0;
  cin >> n >> max_a;
  ll ans = 0;
  for(int i = 1; i < n; ++i)
  {
    cin >> a;
    ans += max(0LL, max_a - a);
    max_a = max(a, max_a);
  }
  cout << ans;

}

int main()
{
  fastio;
  solve();

  return 0;
}