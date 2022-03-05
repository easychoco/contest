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

vector<ll> x, y, z;
ll distance(int from, int to)
{
  ll ret = abs(x[from] - x[to]) + abs(y[from] - y[to]) + max(0LL, z[to] - z[from]);
  return ret;
}

void solve()
{
  ll n;
  cin >> n;
  x = vector<ll>(n);
  y = vector<ll>(n);
  z = vector<ll>(n);

  rep(i, n)
  {
    cin >> x[i] >> y[i] >> z[i];
  }

  vector< vector<ll> > dist(n, vector<ll>(n));
  rep(i, n) rep(j, n) dist[i][j] = distance(i, j);

  const ll INF = 1LL << 60;
  // dp[i][j] = いまjにいて、i(mask)の街に訪れているときのコストの最小値
  vector< vector<ll> > dp(1<<n, vector<ll>(n, INF));
  repi(i, 1, n) dp[1<<i][i] = dist[0][i];

  rep(mask, 1<<n)
  {
    rep(now, n)
    {
      // now の街に来ていなかったら return
      if (~mask >> now & 1) continue;
      rep(next, n)
      {
        // next の街に来ていたら return
        if (mask >> next & 1) continue;
        chmin(dp[mask | (1 << next)][next], dp[mask][now] + dist[now][next]);
      }
    }
  }
  cout << dp[(1 << n) - 1][0];
}

int main()
{
  fastio;
  solve();

  return 0;
}