#include <bits/stdc++.h>
#include <atcoder/all>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i=(a);i<(ll)(n);++i)
#define repe(i,n) repie(i,0,n)
#define repie(i,a,n) for(ll i=(a);i<=(ll)(n);++i)
#define rrep(i,n) rrepi(i,n,0)
#define rrepi(i,n,a) for(ll i=(n);i>=(a);--i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()

using namespace std;
using namespace atcoder;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using P = pair<ll, ll>;
const ll INF = 1LL << 60;
void YN(bool a) { cout << (a ? "Yes" : "No") << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
void show(){ cout << endl; }
template <class Head, class... Tail>
void show(Head&& head, Tail&&... tail){ cout << head << " "; show(std::forward<Tail>(tail)...); }
template<class T> inline void showall(T& a) { for(auto v:a) cout<<v<<" "; cout<<endl; }

ll dp[310][310][310];

void solve()
{
  ll n, x, y;
  cin >> n >> x >> y;
  vector<ll> a(n), b(n);
  rep(i, n)
  {
    cin >> a[i] >> b[i];
  }

  repe(i, n)
  repe(j, x)
  repe(k, y)
  {
    dp[i][j][k] = INF;
  }

  dp[0][0][0] = 0;

  // dp[i][j][k] = i - 1 番目まで見て x が j,  y が k の時の最小個数
  repie(i, 1, n)
  {
    ll ai = a[i - 1];
    ll bi = b[i - 1];
    repe(j, x)
    repe(k, y)
    {
      chmin(dp[i][j][k], dp[i - 1][j][k]);
      ll jj = min(x, j + ai);
      ll kk = min(y, k + bi);
      chmin(dp[i][jj][kk], dp[i - 1][j][k] + 1);
    }
  }

  ll ans = dp[n][x][y];
  if (ans == INF) ans = -1;
  show(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}
