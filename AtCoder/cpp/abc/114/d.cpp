#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
  int n;
  cin >> n;
  if (n < 10) 
  {
    cout << 0;
    return;
  }

  map<int, int> primes;
  for(int i = 1; i <= n; ++i)
  {
    int n = i;
    for(int p = 2; p <= i; ++p)
    {
      while(n % p == 0)
      {
        primes[p]++;
        n /= p;
      }
    }
  }

  int ans = 0;
  int over74 = 0;
  int over24 = 0;
  int over14 = 0;
  int over4 = 0;
  int over2 = 0;
  for(const auto& p : primes)
  {
    if (p.second >= 74) over74++;
    if (p.second >= 24) over24++;
    if (p.second >= 14) over14++;
    if (p.second >=  4) over4++;
    if (p.second >=  2) over2++;
  }

  ans += over74;
  ans += over24 * (over2 - 1);
  ans += over14 * (over4 - 1);
  ans += over4 * (over4 - 1) * (over2 - 2) / 2;
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}