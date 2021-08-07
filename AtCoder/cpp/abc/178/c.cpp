#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()

using namespace std;
using ll = long long;

const double PI = 3.14159265358979;

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

void solve()
{
  int n;
  cin >> n;
  const ll MOD = 1000000007;

  cout << 
    ((powmod(10, n, MOD) 
    - powmod(9, n, MOD) * 2 + MOD * 2) % MOD
    + powmod(8, n, MOD)) % MOD;
}

int main()
{
  fastio;
  solve();

  return 0;
}