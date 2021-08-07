#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;
const int INF = 1 << 30;

void solve()
{
  int d, g, p_input, c_input;
  cin >> d >> g;
  g /= 100;
  vector<int> point(d);
  vector<int> comp(d);

  for(int i = 0; i < d; ++i)
  {
    cin >> p_input >> c_input;
    c_input /= 100;
    point[i] = p_input;
    comp[i] = p_input * (i + 1) + c_input;
  }

  int mask = 1 << d;
  int ans = INF;
  while(mask--, mask >= 0)
  {
    int score = 0;
    int cost = 0;
    for(int i = 0; i < d; ++i)
    {
      if ((mask & (1 << i)) == 0) continue;
      score += comp[i];
      cost += point[i];
    }

    if (score >= g) 
    {
      ans = min(ans, cost);
      continue;
    }

    for(int i = d - 1; i >= 0; --i)
    {
      if(mask & (1 << i)) continue;

      int rest = (g - score) / (i + 1);
      score += min(rest, point[i] - 1) * (i + 1);
      cost += min(rest, point[i] - 1);

      if (score >= g) 
      {
        ans = min(ans, cost);
        break;
      }
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