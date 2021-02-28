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
  char c[4];
  cin >> c;
  cout << (c[0] - '0' + c[1] - '0' + c[2] - '0');
}

int main()
{
  fastio;
  solve();

  return 0;
}