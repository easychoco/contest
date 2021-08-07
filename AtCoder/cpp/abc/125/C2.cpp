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
  for(int i = 0; i < n; ++i)
  {
    cin >> a[i];
  }

  vector<int> L(n, 0), R(n, 0);
  for(int i = 0; i < n - 1; ++i)
  {
    L[i + 1] = gcd(L[i], a[i]);
  }
  for(int i = n - 1; i >= 1; --i)
  {
    R[i - 1] = gcd(R[i], a[i]);
  }

  int ans = 0;
  for(int i = 0; i < n; ++i)
  {
    ans = max(ans, (int)gcd(L[i], R[i]));
  }
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}