#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
  int n, m, nx, ny;
  cin >> n >> m >> nx >> ny;
  vector<int> x(n), y(m);
  for(int i = 0; i < n; ++i) cin >> x[i];
  for(int i = 0; i < m; ++i) cin >> y[i];

  sort(x.begin(), x.end());
  sort(y.begin(), y.end());

  bool ans = true;
  int z = x.back() + 1;
  if (z == nx) z++;

  ans &= (z <= y[0]);
  ans &= (z <= ny);

  cout << (ans ? "No War" : "War");
}

int main()
{
  fastio;
  solve();

  return 0;
}