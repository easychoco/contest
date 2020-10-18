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

void solve()
{
	int n, t;
  cin >> n >> t;
  vector<ll> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];

  auto max_itr = max_element(ALL(b));
  ll max_val = *max_itr;
  *max_itr = 0;

  ll ans = 0;

  // dp[i][j] = i番目の料理まで選んだ時の時刻tでの満足度の最大値
  vector< vector<ll> > dp(n + 1, vector<ll>(t, 0));

  rep(i, n) rep(j, t)
  {
    if (j < a[i]) dp[i + 1][j] = dp[i][j];
    else dp[i + 1][j] = max(dp[i][j], dp[i][j - a[i]] + b[i]);
  }

  ans = dp[n][t-1] + max_val;

  auto max_itr2 = max_element(ALL(b));
  ll max_val2 = *max_itr2;
  *max_itr2 = 0;

  *max_itr = max_val;

  dp = vector< vector<ll> >(n + 1, vector<ll>(t, 0));

  rep(i, n) rep(j, t)
  {
    if (j < a[i]) dp[i + 1][j] = dp[i][j];
    else dp[i + 1][j] = max(dp[i][j], dp[i][j - a[i]] + b[i]);
  }

  chmax(ans, dp[n][t-1] + max_val2);
  cout << ans;
}

int main()
{
	fastio;
	solve();

	return 0;
}