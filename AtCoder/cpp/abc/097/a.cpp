#include <iostream>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << (min( abs(a - c), max( abs(a - b), abs(b - c) ) ) <= d ? "Yes" : "No");
}

int main()
{
  fastio;
  solve();

  return 0;
}