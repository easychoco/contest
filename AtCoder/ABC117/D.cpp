#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
  ll n, k, a_input;
  cin >> n >> k;

  int digit_size = (int)(log(k) / log(2) + 1.0);
  if (k == 0) digit_size = 0;
  vector<ll> digit(digit_size, 0);

  vector<ll> a(n);
  for(int i = 0; i < n; ++i)
  {
    cin >> a_input;
    a[i] = a_input;
    if (digit_size == 0) continue;
    int d = 0;
    while(a_input > 0)
    {
      digit[d] += (a_input & 1);
      a_input >>= 1;
      d++;
    }
  }

  ll num = 0;
  for(int i = digit_size - 1; i >= 0; --i)
  {
    ll d = ((digit[i] * 2 <= n ? 1LL : 0LL) << i);
    if (num + d <= k) num += d;
  }

  ll ans = 0;
  for(int i = 0; i < n; ++i)
  {
    ans += (a[i] ^ num);
  }
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}