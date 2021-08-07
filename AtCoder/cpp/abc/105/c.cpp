#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
  int n;
  cin >> n;
  string ans = ((n == 0) ? "0" : "");
  while(n != 0)
  {
    ans += (n % 2 == 0 ? '0' : '1');
    n -= (n % 2 == 0 ? 0 : 1);
    // 負の値に対して割り算の切り捨てをしようとするとずれる。切り上げになってしまう。
    // そうならないように、あまりを引いて桁をそろえる
    n /= -2;
  }
  reverse(ans.begin(), ans.end());
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}