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
  int ans = 0;
  int num = 1;
  while(num+=2, num <= n)
  {
    int cnt = 1;
    for(int i = 3; i * i < num; i+=2)
    {
      cnt += (num % i == 0);
    }
    ans += (cnt == 4);
  }
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}