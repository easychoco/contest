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
  int n, pin;
  cin >> n;
  vector<int> p(n + 1, 0);
  for(int i = 1; i <= n; ++i)
  {
    cin >> pin;
    p[i - 1] = (pin == i);
  }
  int ans = 0;
  for(int i = 0; i < n; ++i)
  {
    if (p[i]) p[i + 1] = 0;
    ans += p[i];
  }
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}