#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
  int n;
  cin >> n;

  char next_top;
  set<string> pool;
  string w;

  cin >> w;
  next_top = w.back();
  pool.insert(w);

  for(int i  = 1; i < n; ++i)
  {
    cin >> w;
    if(w[0] != next_top || pool.find(w) != pool.end())
    {
      cout << "No";
      return;
    }
    next_top = w.back();
    pool.insert(w);
  }
  cout << "Yes";
}

int main()
{
  fastio;
  solve();

  return 0;
}