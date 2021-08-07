#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

// a^n % mod を計算する O(log n)
ll powmod(ll a, ll n, ll mod) {
  ll ret = 1;
  while (n > 0) {
    if (n % 2 == 1) { ret = ret * a % mod; }
    a = a * a % mod;
    n /= 2;
  }
  return ret;
}

int calc(ll num, int depth)
{
  if (num == 0LL) return depth;

  int p_count = __builtin_popcount(num);
  return calc(ll(num % p_count), depth + 1);
}

void solve()
{
  ll n;
  string s;
  cin >> n >> s;

  ll p_count = 0;
  for(int i = 0; i < n; ++i) p_count += (s[i] == '1');
  ll rem_p1 = 0;
  ll rem_m1 = 0;

  for(int i = 1; i <= n; ++i)
  {
    if (s[n - i] == '1')
    {
      rem_p1 += powmod(2LL, i - 1, p_count + 1);
      rem_p1 %= (p_count + 1);

      if (p_count > 1)
      {
        rem_m1 += powmod(2LL, i - 1, p_count - 1);
        rem_m1 %= (p_count - 1);
      }
    }
  }

  for(int i = 0; i < n; ++i)
  {
    if (s[i] == '1')
    {
      if (p_count == 1)
      {
        cout << 0 << endl;
        continue;
      }
      ll rem = rem_m1 - powmod(2, n - i - 1, p_count - 1);
      rem = (rem + (p_count - 1)) % (p_count - 1);
      cout << calc(rem, 1) << endl;
    }
    else if (s[i] == '0')
    {
      if (p_count == 0)
      {
        cout << 1 << endl;
      }
      else
      {      
        ll rem = rem_p1 + powmod(2, n - i - 1, p_count + 1);
        rem = rem % (p_count + 1);
        cout << calc(rem, 1) << endl;
      }
    }
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}