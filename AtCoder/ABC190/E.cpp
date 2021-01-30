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
  vector< vector<int> > edge(n, vector<int>());
  for(int i = 0; i < m; ++i)
  {
    ll a, b;
    cin >> a >> b;
    a--; b--;
    edge[a].emplace_back(b);
    edge[b].emplace_back(a);
  }

  ll k;
  cin >> k;
  if (k == 1)
  {
    cout << 1;
    return;
  }
  vector<ll> c(k);
  vector< vector<ll> > d(k, vector<ll>(n, 1LL<<60));
  rep(i, k)
  {
    cin >> c[i];
    c[i]--;

    queue<int> que;
    que.push(c[i]); //初期位置
    d[i][c[i]] = 0;
    while(!que.empty())
    {
      int now = que.front();
      que.pop();
      for(const auto& to : edge[now])
      {
        if (chmin(d[i][to], d[i][now] + 1))
          que.push(to);
      }
    }
  }

  n = k;

  // tsp
  // traveling salesman
  // 巡回セールスマン問題
  const ll INF = 1LL << 60;
  // dp[i][j] = いまjにいて、i(mask)の街に訪れているときのコストの最小値
  vector< vector<ll> > dp(1<<n, vector<ll>(n, INF)), dist(n, vector<ll>(n, INF));

  rep(i, n) rep(j, n)
  {
    dist[i][j] = d[i][c[j]];
  }
  rep(i, n) dp[1 << i][i] = 1;
  rep(mask, 1<<n) rep(now, n)
  {
    if ((1 << now) & mask) rep(next, n)
    {
      if ((1 << next) & mask) continue;
      chmin(dp[mask | (1<<next)][next], dp[mask][now] + dist[now][next]);
    }
  }
  ll ans = INF;
  rep(i, n) chmin(ans, dp[(1 << n) - 1][i]);
  if (ans == INF) ans = -1;
  cout << ans << endl;
}

int main()
{
  fastio;
  solve();

  return 0;
}