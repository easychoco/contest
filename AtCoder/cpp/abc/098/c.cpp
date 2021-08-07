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
  string s;
  cin >> n >> s;
  vector<int> W(n, 0), E(n, 0);
  for(int i = 0; i < n - 1; ++i)
  {
    W[i + 1] = W[i] + (s[i] == 'W');
  }
  int ans = W.back();
  for(int i = n - 1; i >= 1; --i)
  {
    E[i - 1] = E[i] + (s[i] == 'E');
    ans = min(ans, W[i - 1] + E[i - 1]);
  }
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}