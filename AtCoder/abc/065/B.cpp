#include <bits/stdc++.h>

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
    a[i]--;
  }

  int now = 0;
  for(int i = 0; i < n; ++i)
  {
    now = a[now];
    if(now == 1)
    {
      cout << i + 1;
      return;
    }
  }
  cout << -1;
}

int main()
{
  fastio;
  solve();

  return 0;
}