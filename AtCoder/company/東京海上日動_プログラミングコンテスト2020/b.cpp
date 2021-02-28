#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll = long long;

const double PI = 3.14159265358979;

void solve()
{
  ll a, v, b, w, t;
  cin >> a >> v >> b >> w >> t;
  cout << (abs(a - b) <= (v - w) * t ? "YES" : "NO");
}

int main()
{
  fastio;
  solve();

  return 0;
}