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
  int a, b, k;
  cin >> a >> b >> k;

  int cd = gcd(a, b);
  for(int i = cd; i >= 0; --i)
  {
    if (cd % i == 0) k--;
    if (k == 0)
    {
      cout << i;
      break;
    }
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}