#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

ll b_num[55], p_num[55];

void solve()
{
  ll n, x;
  cin >> n >> x;

  b_num[0] = 1;
  p_num[0] = 1;

  for(int i = 1; i <= 50; ++i)
  {
    b_num[i] = b_num[i - 1] * 2 + 3;
    p_num[i] = p_num[i - 1] * 2 + 1;
  }

  auto lv_mid = [&](ll lv){ return (b_num[lv] + 1) / 2LL; };
  ll ans = 0;
  ll pos = 0;
  for(int lv = n; lv >= 0; --lv)
  {
    ll mid = lv_mid(lv);

    // 半分より左
    if (x < mid + pos)
    {
      pos++;
      continue;
    }

    if (lv > 0) ans += p_num[lv - 1] + 1;
    else ans++;

    // ちょうど半分
    if (x == mid + pos) break;

    // 半分より右
    pos += mid;
  }
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}