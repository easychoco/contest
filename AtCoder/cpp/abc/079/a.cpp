#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll = long long;

const double PI = 3.14159265358979;

void solve()
{
  int n;
  cin >> n;
  cout << (((n / 10) % 111 == 0) || ((n % 1000) % 111 == 0) ? "Yes" : "No");
}

int main()
{
  fastio;
  solve();

  return 0;
}