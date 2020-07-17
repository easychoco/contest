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
  vector<int> p(n);
  for(int i = 0; i < n; ++i)
  {
    cin >> p[i];
  }
  int ans = accumulate(p.begin(), p.end(), 0) - *max_element(p.begin(), p.end()) / 2;
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}