#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll = long long;

const double PI = 3.14159265358979;

void solve()
{
  int a, b, c, x;
  cin >> a >> b >> c >> x;
  int ans = 0;
  for(int i50 = 0; i50 <= a; ++i50)
  for(int i10 = 0; i10 <= b; ++i10)
  for(int i5  = 0; i5  <= c; ++i5)
  {
    if (500*i50 + 100*i10 + 50*i5 == x) ans++;
  }
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}