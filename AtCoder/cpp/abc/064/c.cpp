#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()

using namespace std;
using ll = long long;

const double PI = 3.14159265358979;

int c[9];
void solve()
{
  int n, a;
  cin >> n;
  for(int i = 0; i < n; ++i)
  {
    cin >> a;
    a = min(8, a / 400);
    c[a]++;
  }
  int ans = 0;
  for(int i = 0; i < 8; ++i)
  {
    ans += (c[i] > 0);
  }
  if (ans == 0)
  {
    cout << 1 << " " << c[8];
    return;
  }
  cout << ans << " " << ans + c[8];
}

int main()
{
  fastio;
  solve();

  return 0;
}