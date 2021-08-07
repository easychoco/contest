#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
  int n, m, c;
  cin >> n >> m >> c;
  vector<int> b(m);
  for(int i = 0; i < m; ++i) cin >> b[i];

  int ans = 0;
  for(int i = 0; i < n; ++i) 
  {
    int score = 0;
    int a;
    for(int j = 0; j < m; ++j)
    {
      cin >> a;
      score += b[j] * a;
    }
    ans += score + c > 0;
  }
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}