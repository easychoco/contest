#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()

using namespace std;
using ll = long long;

const double PI = 3.14159265358979;

void solve()
{
  ll n, a;
  cin >> n;
  int ans = 100000;
  for(int i = 0; i < n; ++i)
  {
    cin >> a;
    int num = 0;
    while((a & 1) == 0)
    {
      a /= 2;
      num++;
    }
    ans = min(ans, num);
  }
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}