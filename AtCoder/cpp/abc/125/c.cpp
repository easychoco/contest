#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

// 最大公約数 : 3,4 ->  1
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

void solve()
{
  int n;
  cin >> n;
  vector<int> a(n);
  cin >> a[0] >> a[1];
  if (n == 2)
  {
    cout << max(a[0], a[1]);
    return;
  }

  cin >> a[2];
  int gcd0 = gcd(a[1], a[2]);
  int gcd1 = gcd(a[0], a[2]);
  int gcd2 = gcd(a[0], a[1]);

  int now_gcd = max({gcd0, gcd1, gcd2});
  int may_waste_gcd = gcd(gcd0, a[0]);

  for(int i = 3; i < n; ++i)
  {
    cin >> a[i];
    if (a[i] % now_gcd == 0) continue;

    int tmp_gcd = gcd(a[i], now_gcd);
    now_gcd = max(tmp_gcd, may_waste_gcd);
    may_waste_gcd = gcd(a[i], may_waste_gcd);
  }
  cout << now_gcd;
}

int main()
{
  fastio;
  solve();

  return 0;
}