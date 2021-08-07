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
  int n, a, ans;
  cin >> n >> ans;
  for(int i = 1; i < n; ++i)
  {
    cin >> a;
    ans = gcd(a, ans);
  }
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}