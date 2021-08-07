// https://atcoder.jp/contests/abc142/tasks/abc142_e
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
  ll n, m;
  cin >> n >> m;
  vector<ll> a(m);
  vector<ll> c(m, 0);
  rep(i, m)
  {
    ll b, inc;
    cin >> a[i] >> b;
    rep(j, b)
    {
      cin >> inc;
      inc--;
      c[i] += (1LL<<inc);
    }
  }

  ll INF = 1LL << 60;
  // dp[mask] = maskの宝箱をあけられるときに必要な最小コスト
  vector<ll> dp(1<<n, INF);
  dp[0] = 0;

  rep(mask, 1<<n)
  {
    rep(i, m)
    {
      chmin(dp[mask | c[i]], dp[mask] + a[i]);
    }
  }

  if (dp[(1<<n) - 1] == INF) dp[(1<<n) - 1] = -1;
  cout << dp[(1<<n) - 1] << endl;
}

int main()
{
  fastio;
  solve();

  return 0;
}