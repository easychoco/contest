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
  vector<int> l(n);
  for(int i = 0; i < n; ++i)
  {
    cin >> l[i];
  }
  sort(l.begin(), l.end());
  int sum = accumulate(l.begin(), l.end(), 0);
  cout << (l.back() * 2 < sum ? "Yes" : "No");
}

int main()
{
  fastio;
  solve();

  return 0;
}