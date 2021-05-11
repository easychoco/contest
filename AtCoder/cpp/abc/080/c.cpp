#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll = long long;

const double PI = 3.14159265358979;

void solve()
{
  int n, fin;
  cin >> n;
  vector<ll> f(n);
  vector< vector<ll> > p(n, vector<ll>(11));
  for(int i = 0; i < n; ++i) for(int j = 0; j < 10; ++j)
  {
    cin >> fin;
    f[i] += (fin << j);
  }
  for(int i = 0; i < n; ++i) for(int j = 0; j < 11; ++j)
  {
    cin >> p[i][j];
  }
  ll ans = -1e9;
  for(int mask = 1; mask <= (1 << 10) - 1; ++mask)
  {
    ll ben = 0;
    for(int i = 0; i < n; ++i)
    {
      bitset<10> b(mask & f[i]);
      ben += p[i][b.count()];
    }
    ans = max(ans, ben);
  }
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}