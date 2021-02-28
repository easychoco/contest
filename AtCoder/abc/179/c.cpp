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
  ll n;
  cin >> n;
  int ans= 0;
  // c = n - a*b
  // 1 <= n - a*b
  // a*b <= n-1
  for(int a = 1; a < n; ++a)
  {
    ans += (n - 1) / a;
  }

  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}