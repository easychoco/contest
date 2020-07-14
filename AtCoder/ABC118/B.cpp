#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
  int n, m, k, a;
  cin >> n >> m;
  vector<int> bin(m);
  for(int i = 0; i < n; ++i)
  {
    cin >> k;
    for(int j = 0; j < k; ++j)
    {
      cin >> a;
      bin[a - 1]++;
    }
  }

  int ans = 0;
  for(int i = 0; i < m; ++i)
  {
    ans += bin[i] == n;
  }
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}