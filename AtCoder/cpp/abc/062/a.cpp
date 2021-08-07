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
  int b[13] = { 0, 1, 2, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1 };
  int x, y;
  cin >> x >> y;
  cout << (b[x] == b[y] ? "Yes" : "No");
}

int main()
{
  fastio;
  solve();

  return 0;
}