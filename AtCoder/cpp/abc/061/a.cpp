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
  int a, b, c;
  cin >> a >> b >> c;
  cout << ((a <= c && c <= b) ? "Yes" : "No");
}

int main()
{
  fastio;
  solve();

  return 0;
}
