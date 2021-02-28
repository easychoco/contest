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
  ll n, k;
  cin >> n >> k;
  vector<ll> l(n);
  for(int i = 0; i < n; ++i)
  {
    cin >> l[i];
  }
  sort(RALL(l));
  ll ans = 0;
  for(int i = 0; i < k; ++i) ans += l[i];
  cout << ans;

}

int main()
{
  fastio;
  solve();

  return 0;
}