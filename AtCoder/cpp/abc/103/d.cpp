#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
  int n, m, ina, inb;
  cin >> n >> m;
  vector<vector<int>> a(n + 1, vector<int>());
  for(int i = 0; i < m; ++i)
  {
    cin >> ina >> inb;
    a[ina].emplace_back(inb);
  }

  const int INF = 1 << 30;

  int border = INF;
  int ans = 0;
  for(int i = 0; i < n; ++i)
  {
    if (border <= i)
    {
      ans++;
      border = INF;
    }
    if (a[i].size() == 0) continue;
    border = min(border, *min_element(a[i].begin(), a[i].end()) );
  }
  ans += (border != INF);
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}