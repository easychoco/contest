// https://atcoder.jp/contests/abc073/tasks/abc073_d
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
  ll n, m, r;
  cin >> n >> m >> r;
  vector<ll> town(r);
  rep(i, r)
  {
    cin >> town[i];
    town[i]--;
  }

  const ll INF = 100100100100;
  const int N = 300;
  ll d[N][N];
  rep(i, N) rep(j, N) d[i][j] = INF;
  rep(i, N) d[i][i] = 0;
  
  rep(i, m)
  {
    ll a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    d[a][b] = c;
    d[b][a] = c;
  }  

  rep (k, n){       // 経由する頂点
    rep (i, n) {    // 始点
      rep (j, n) {  // 終点
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }

  sort(ALL(town));
  ll ans = INF;
  do {
    ll cost = 0;
    rep(i, r - 1) cost += d[town[i]][town[i + 1]];
    chmin(ans, cost);
  } while(next_permutation(ALL(town)));

  Showln(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}