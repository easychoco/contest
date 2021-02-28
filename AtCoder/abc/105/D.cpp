#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n);
  for(ll i = 0; i < n; ++i) cin >> a[i];
  vector<ll> sum(a);
  for(ll i = 1; i < n; ++i) sum[i] += sum[i - 1];
 
  map<ll, ll> mp;
  for(const auto& v : sum) mp[v % m]++;

  ll ans = mp[0];
  for(const auto& m : mp)
  {
    ll v = m.second;
    ans += v * (v - 1) / 2;
  }
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}