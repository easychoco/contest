#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll = long long;

const double PI = 3.14159265358979;

void solve()
{
  string a, b;
  cin >> a >> b;
  int n = stoi(a + b);
  for(int i = 0; i * i <= n; ++i)
  {
    if (i * i == n)
    {
      cout << "Yes";
      return;
    }
  }
  cout << "No";
}

int main()
{
  fastio;
  solve();

  return 0;
}