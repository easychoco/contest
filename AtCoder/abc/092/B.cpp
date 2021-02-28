#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll = long long;

const double PI = 3.14159265358979;

void solve()
{
  int n, d, x, a;
  cin >> n >> d >> x;
  int ans = 0;
  for(int i = 0; i < n; ++i)
  {
    cin >> a;
    ans += 1 + (d - 1) / a;
  }
  cout << ans + x;
}

int main()
{
  fastio;
  solve();

  return 0;
}