#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ALL(a) (a).begin(),(a).end()
#define X first
#define Y second

using namespace std;
using ll = long long;
using P = pair<int, int>;


const double PI = 3.14159265358979;

void solve()
{
  ll n, a, b, c, d;
  cin >> n;
  vector<P> red(n);
  vector<P> blue(n);
  vector<bool> r_used(n, false);
  for(int i = 0; i < n; ++i)
  {
    cin >> a >> b;
    red[i] = P(a, b);
  }
  for(int i = 0; i < n; ++i)
  {
    cin >> c >> d;
    blue[i] = P(c, d);
  }

  sort(ALL(blue));

  int ans = 0;  
  for(int i = 0; i < n; ++i)
  {
    int rj = -1;
    for(int j = 0; j < n; ++j)
    {
      if (r_used[j]) continue;
      if (red[j].X < blue[i].X && red[j].Y < blue[i].Y)
      {
        if ((rj == -1) || red[rj].Y < red[j].Y)
        {
          rj = j;
        }
      }
    }
    if (rj != -1)
    {
      r_used[rj] = true;
      ans++;
    }
  }
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}