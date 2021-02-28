// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()

using namespace std;
using ll = long long;

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
  for(int i = 1; i < n; ++i)
  {
    a[i] += a[i - 1];
  }
  ll ans = (1LL << 60);
  for(int i = 0; i < n - 1; ++i)
  {
    ans = min(ans, abs(a.back() - 2 * a[i]));
  }
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}