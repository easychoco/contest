#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

bool check357(ll num)
{
  bool ret3 = false;
  bool ret5 = false;
  bool ret7 = false;
  while(num > 0)
  {
    int res = num % 10;
    ret3 |= (res == 3);
    ret5 |= (res == 5);
    ret7 |= (res == 7);
    num /= 10;
  }
  return (ret3 & ret5 & ret7);
}

ll n;
ll ans = 0;

void dfs(ll num, ll digit)
{
  if (num > n) return;
  if (num > 100) ans += check357(num);

  dfs(num + digit * 3, digit * 10);
  dfs(num + digit * 5, digit * 10);
  dfs(num + digit * 7, digit * 10);
}

void solve()
{
  cin >> n;

  dfs(0, 1);
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}