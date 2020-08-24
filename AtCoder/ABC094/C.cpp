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
  vector<int> x(n);
  for(int i = 0; i < n; ++i)
  {
    cin >> x[i];
  }
  vector<int> origin(x);
  sort(x.begin(), x.end());
  ll midl = x[n / 2 - 1];
  ll midr = x[n / 2];

  for(const auto& v : origin)
  {
    cout << (v <= midl ? midr : midl) << endl;
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}