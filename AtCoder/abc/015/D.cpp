#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i = a;i < (ll)n;++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define SHOW(str,val) cout<<(str)<<" : "<<(val)<<endl;

using namespace std;
using ll = long long;
using P = pair<ll, ll>;
// using P = pair<int, int>;
void YN(bool a) { cout << (a ? "Yes" : "No"); }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true;} return false;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true;} return false;}

// dp[i][j][x] = i枚まで見て、j枚選んで幅がxの時の最大重要度
ll dp[55][55][11010];

void solve()
{
  int w, n, k;
  cin >> w >> n >> k;
  vector<ll> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];
  rep(i, n) rep(j, k + 1) rep(x, w + 1)
  {
    chmax(dp[i + 1][j + 1][x + a[i]], dp[i][j][x] + b[i]);
    chmax(dp[i + 1][j][x], dp[i][j][x]);
  }
  cout << dp[n][k][w];
}

int main()
{
  fastio;
  solve();

  return 0;
}