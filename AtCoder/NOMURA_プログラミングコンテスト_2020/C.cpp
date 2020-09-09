#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll = long long;

const double PI = 3.14159265358979;

void solve()
{
  ll n;
  cin >> n;
  n++;
  vector<ll> a(n);
  for(int i = 0; i < n; ++i)
  {
    cin >> a[i];
  }

  vector<ll> b(a);
  for(int i = n - 2; i >= 0; --i)
  {
    b[i] += b[i + 1];
  }

  ll next_branch = 1;  
  ll ans = 0;
  for(int i = 0; i < n; ++i)
  {
    b[i] = min(b[i], next_branch);
    next_branch = min((next_branch - a[i]) * 2, (1LL << 62));
    if (next_branch < 0){
      cout << -1;
      return;
    }
    ans += b[i];
  }
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}