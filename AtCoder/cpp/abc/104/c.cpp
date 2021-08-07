#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;
const int INF = 1 << 30;

int score[400000];

void solve()
{
  fill(score, score + 400000, INF);
  score[0] = 0;

  int d, g, p_input, c_input;
  cin >> d >> g;
  g /= 100;
  vector< vector<int> > point(d, vector<int>());

  for(int i = 0; i < d; ++i)
  {
    cin >> p_input >> c_input;
    c_input /= 100;
    for(int j = 0; j < p_input; ++j)
    {
      point[i].emplace_back( (i+1) * (j+1) );
    }
    point[i].back() += c_input;
  }

  // 1点問題
  for(int p = 1; p <= point[0].size(); ++p) score[point[0][p - 1]] = p;
  int over = point[0].back();

  // sc点問題
  for(int sc = 2; sc <= d; ++sc)
  {
    int sc_index = sc - 1;
    for(int s = min(g, over); s >= 0; --s)
    {
      if (score[s] != INF)
      for(int p = 1; p <= point[sc_index].size(); ++p)
      {
        score[s + point[sc_index][p - 1]] = min(score[s + point[sc_index][p - 1]], score[s] + p);
      }
    }
    over += point[sc_index].back();
  }

  int ans = INF;
  for(int i = g; i <= over; ++i) ans = min(ans, score[i]);
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}