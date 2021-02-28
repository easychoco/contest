#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;

  int vx = y1 - y2;
  int vy = x2 - x1;

  cout << x2 + vx << " " << y2 + vy << " ";
  cout << x1 + vx << " " << y1 + vy;
}

int main()
{
  fastio;
  solve();

  return 0;
}