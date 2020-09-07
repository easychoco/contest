#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll = long long;

const double PI = 3.14159265358979;

void solve()
{
  int n, a, b;
  cin >> n >> a >> b;
  cout << min(n * a , b);
}

int main()
{
  fastio;
  solve();

  return 0;
}