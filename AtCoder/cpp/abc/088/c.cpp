#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll = long long;

const double PI = 3.14159265358979;

void solve()
{
  int c[3][3];
  for(int i = 0; i < 3; ++i)
  {
    cin >> c[i][0];
    cin >> c[i][1];
    cin >> c[i][2];
  }
  int a12 = abs(c[0][0] + c[0][1] + c[0][2] - (c[1][0] + c[1][1] + c[1][2]));
  int a23 = abs(c[1][0] + c[1][1] + c[1][2] - (c[2][0] + c[2][1] + c[2][2]));
  int a13 = abs(c[0][0] + c[0][1] + c[0][2] - (c[2][0] + c[2][1] + c[2][2]));

  int b12 = abs(c[0][0] + c[1][0] + c[2][0] - (c[0][1] + c[1][1] + c[2][1]));
  int b23 = abs(c[0][1] + c[1][1] + c[2][1] - (c[0][2] + c[1][2] + c[2][2]));
  int b13 = abs(c[0][0] + c[1][0] + c[2][0] - (c[0][2] + c[1][2] + c[2][2]));

  if (a12 % 3 + a23 % 3 + a13 % 3 + b12 % 3 + b23 % 3 + b13 % 3 == 0)
    cout << "Yes";
  else cout << "No";
}

int main()
{
  fastio;
  solve();

  return 0;
}