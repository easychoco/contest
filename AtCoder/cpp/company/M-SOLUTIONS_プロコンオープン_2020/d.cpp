#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
  ll n;
  cin >> n;
  vector<ll> a(n);
  for(int i = 0; i < n; ++i)
  {
    cin >> a[i];
  }

  ll val = 1000;
  ll min_val = a[0];
  ll max_val = a[0];
  a.erase(unique(a.begin(), a.end()), a.end());
  for(int i = 1; i < a.size(); ++i)
  {
    if (a[i - 1] > a[i])
    {
      val += (val / min_val) * (max_val - min_val);
      max_val = min_val = a[i];
    }
    max_val = max(max_val, a[i]);
    min_val = min(min_val, a[i]);
  }

  val += (val / min_val) * (max_val - min_val);
  cout << val;
}

int main()
{
  fastio;
  solve();

  return 0;
}