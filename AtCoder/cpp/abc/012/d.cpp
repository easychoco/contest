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
  ll n, m, a, b, t;
  cin >> n >> m;

  const ll INF = 100100100100;
  ll d[300][300];
  rep(i, 300) rep(j, 300) d[i][j] = INF;
  rep(i, 300) d[i][i] = 0;
  rep(i, m)
  {
    cin >> a >> b >> t;
    a--; b--;
    d[a][b] = t;
    d[b][a] = t;
  }

  rep (k, n){       // 経由する頂点
    rep (i, n) {    // 始点
      rep (j, n) {  // 終点
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }

  ll ans = INF;
  rep(i, n) 
  {
    ll tmp = 0;
    rep(j, n) if (d[i][j] < INF) chmax(tmp, d[i][j]);
    chmin(ans, tmp);
  }
  cout << ans << endl;

}

int main()
{
  fastio;
  solve();

  return 0;
}