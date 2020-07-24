#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
  ll n, k;
  cin >> n >> k;

  ll c_od = 0;
  ll c_ev = 0;

  if (k & 1)
  {
    // 奇数
    c_od = n / k;
  }
  else
  {
    // 偶数
    ll cnt = n / (k / 2);
    c_od = (cnt + 1) / 2;
    c_ev = cnt / 2;
  }
  cout << c_od * c_od * c_od + c_ev * c_ev * c_ev;
}

int main()
{
  fastio;
  solve();

  return 0;
}