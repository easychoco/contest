#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

//15min
void solve()
{
  int n;
  cin >> n;

  const ll INF = 1LL << 60;
  ll dp[100010];  
  fill(dp, dp + 100010, INF);
  dp[0] = 0;

  vector<int> yen { 1 };

  int num = 6;
  while(num <= n)
  {
    yen.emplace_back(num);
    num *= 6;
  }

  num = 9;
  while(num <= n)
  {
    yen.emplace_back(num);
    num *= 9;
  }

  sort(yen.rbegin(), yen.rend());

  for(int i = 0; i <= n; ++i)
  {
    for(const auto& y : yen)
    {
      if (i + y > n) continue;
      dp[i + y] = min(dp[i + y], dp[i] + 1);
    }
  }

  cout << dp[n];
}

int main()
{
  fastio;
  solve();

  return 0;
}