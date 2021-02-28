#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i=a;i<(ll)n;++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define Show(val) cout<<(val)<<" "
#define Showln(val) cout<<(val)<<endl

using namespace std;
using ll = long long;
using P = pair<ll, ll>;
// using P = pair<int, int>;
void YN(bool a) { cout << (a ? "Yes" : "No"); }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int path[16][16];

void solve()
{
  ll n, m, x, y;
  cin >> n >> m;
  vector<ll> dp(1<<n, 0);
  rep(i, m)
  {
    cin >> x >> y;
    --x; --y;
    path[x][y] = 1;
  }

  dp[0] = 1;
  rep(mask, 1<<n)
  {
    rep(i, n)
    {
      if (mask >> i & 1) continue;
      bool ok = true;
      rep (j, n)
      {
        if ((mask >> j & 1) && path[i][j]) ok = false;
      }
      if (ok) dp[mask | (1<<i)] += dp[mask];
    }
  }
  cout << dp[(1<<n) - 1];
}

int main()
{
  fastio;
  solve();

  return 0;
}