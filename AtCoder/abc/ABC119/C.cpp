#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
  int n, a, b, c;
  cin >> n >> a >> b >> c;
  vector<int> l(n);
  vector<int> target{a, b, c};
  for(int i = 0; i < n; ++i)
  {
    cin >> l[i];
  }

  sort(l.begin(), l.end());
  sort(target.begin(), target.end());

  int ans = 1 << 30;
  do
  {
    do
    {
      int ti = 0;
      int cost = 0;
      int now_len = 0;
      for(int li = 0; li < n; ++li)
      {
        if(ti >= 3) break;
        now_len += l[li];
        int guchoku_cost = abs(now_len - target[ti]);
        int gattai_cost = (li + 1 < n) ? abs(now_len + l[li + 1] - target[ti]) + 10 : 1000000;

        if (guchoku_cost < gattai_cost)
        {
          cost += guchoku_cost;
          now_len = 0;
          ti++;
        }
        else
        {
          cost += 10;
        }
      }
      if (ti >= 3)
      {
        ans = min(ans, cost);
      }
    } while(next_permutation(l.begin(), l.end()));
  } while(next_permutation(target.begin(), target.end()));
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}