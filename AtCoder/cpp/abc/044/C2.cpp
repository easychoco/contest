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

void solve()
{
  int n, a, xi;
  cin >> n >> a;
  vector<int> x(n);
  rep(i, n)
  {
    cin >> xi;
    x[i] = xi - a;
  }

  // dp[i][j] = i番目までいくつか選んだ合計がj - n*aになる選び方の総数
  vector< vector<ll> > dp(n + 1, vector<ll>(2*n*a + 1, 0));

  dp[0][n*a] = 1;
  rep(i, n) rep(j, 2*n*a + 1)
  {
    if (0 <= j - x[i] && j - x[i] <= 2*n*a)
         dp[i + 1][j] = dp[i][j] + dp[i][j - x[i]];
    else dp[i + 1][j] = dp[i][j];
  }
  cout << dp[n][n * a] - 1;
}

int main()
{
  fastio;
  solve();

  return 0;
}