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
  int n, x;
  cin >> n >> x;
  vector<int> pos(n);
  for(int i = 0; i < n; ++i)
  {
    cin >> pos[i];
  }

  int min_pos = *min_element(pos.begin(), pos.end());
  x -= min_pos;

  int ans = abs(x);
  for(int i = 0; i < n; ++i)
  {
    ans = gcd(ans, pos[i] - min_pos);
  }
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}