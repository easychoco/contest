#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

//1125~1330
void solve()
{
  ll n;
  cin >> n;
  vector<ll> a(n);

  ll ans = n;
  int num = 0;
  int le = 0;
  for(int re = 0; re < n; ++re)
  {
    cin >> a[re];
    while((num & a[re]) > 0) 
    {
      num ^= a[le];
      le++;
    }
    num ^= a[re];
    ans += (re - le);
  }
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}