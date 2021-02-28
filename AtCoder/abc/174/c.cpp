#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

void solve()
{
  int k;
  cin >> k;

  if (k % 2 == 0)
  {
    cout << -1;
    return;
  }

  ll num = 0;
  for(int i = 1; i <= k; ++i)
  {
    num = num * 10 + 7;
    num %= k;
    if (num == 0)
    {
      cout << i;
      return;
    }
  }  
  cout<< -1;
}

int main()
{
  fastio;
  solve();

  return 0;
}