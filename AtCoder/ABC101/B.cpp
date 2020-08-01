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

  int num = n;
  int a = 0;

  while(num > 0)
  {
    a += num % 10;
    num /= 10;
  }
  cout << (n % a == 0 ? "Yes" : "No");
}

int main()
{
  fastio;
  solve();

  return 0;
}