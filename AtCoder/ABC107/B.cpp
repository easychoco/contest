#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
  int h, w;
  cin >> h >> w;
  vector<string> a(h);
  for(int i = 0; i < h; ++i)
  {
    cin >> a[i];
  }

  vector<int> erased_h;
  vector<int> erased_w;
  for(int i = 0; i < h; ++i)
  {
    if (a[i] == string(w, '.')) erased_h.emplace_back(i);
  }
  erased_h.emplace_back(1000);

  for(int i = 0; i < w; ++i)
  {
    bool ok = true;
    for(int j = 0; j < h; ++j)
    {
      ok &= (a[j][i] == '.');
    }
    if(ok) erased_w.emplace_back(i);
  }

  reverse(erased_w.begin(), erased_w.end());
  for(int i = 0; i < h; ++i)
  {
    for(const auto& e : erased_w)
    {
      a[i].erase(a[i].begin() + e);
    }
  }

  int eh = 0;
  for(int i = 0; i < h; ++i)
  {
    if (erased_h[eh] == i)
    {
      eh++;
      continue;
    }
    cout << a[i] << endl;
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}