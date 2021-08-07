#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
  int n, x, y;
  cin >> n;
  bool odd = true;
  int size = 20;
  vector<string> ans(n);
  for(int i = 0; i < n; ++i)
  {
    cin >> x >> y;
    if (i == 0)
    {
      odd = ((abs(x) + abs(y)) & 1);
      size += odd;
    }
    if (((x + y) & 1) != odd)
    {
      cout << -1;
      return;
    }
    if (abs(x) + abs(y) > 20)
    {
      cout << -1;
      return;
    }

    for(int h = 0; h < abs(x); ++h)
    {
      ans[i] += x < 0 ? 'L' : 'R';
    }
    for(int v = 0; v < abs(y); ++v)
    {
      ans[i] += y < 0 ? 'D' : 'U';
    }

    while (ans[i].length() < size)
    {
      ans[i] += "LR";
    }
  }

  cout << size << endl;
  for(int i = 0; i < size; ++i) cout << 1 << " ";
  cout << endl;
  for(const auto& a : ans)
  {
    cout << a << endl;
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}