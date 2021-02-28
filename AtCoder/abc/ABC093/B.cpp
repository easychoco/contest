#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
  int a, b, k;
  cin >> a >> b >> k;
  int num = a;
  for(num; num <= min(a + k - 1, b); ++num)
  {
    cout << num << endl;
  }
  for(num = max(num, b - k + 1); num <= b; ++num)
  {
    cout << num << endl;
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}