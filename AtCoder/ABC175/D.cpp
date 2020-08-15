#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
  ll n, k;
  cin >> n >> k;
  vector<ll> c(n + 1, 0);
  vector<ll> p(n + 1, 0);
  for(int i = 1; i <= n; ++i) cin >> p[i];
  for(int i = 1; i <= n; ++i) cin >> c[i];

  const ll INF = 1000000000LL * 5000LL + 10LL;

}

int main()
{
  fastio;
  solve();

  return 0;
}