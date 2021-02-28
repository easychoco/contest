#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
  int n;
  cin >> n;
  if (n == 1)
  {
    cout << "Hello World";
    return;
  }
  int a, b;
  cin >> a >> b;
  cout << a + b;
}

int main()
{
  fastio;
  solve();

  return 0;
}