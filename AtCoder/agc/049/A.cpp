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
  ll n;
  string s;
  cin >> n;

  const ll INF = 100100100100;
  const int N = 100;
  ll d[N][N];
  rep(i, N) rep(j, N) d[i][j] = INF;
  rep(i, N) d[i][i] = 0;

  ll all = 0;
  vector<ll> indi;
  rep(i, n)
  {
    cin >> s;
    // 独立頂点は別に記憶
    if (s == string(n, '0')) { indi.emplace_back(i); continue; }
    rep(j, n) if (s[j] == '1') d[i][j] = 1;
  }

  rep (k, n){       // 経由する頂点
    rep (i, n) {    // 始点
      rep (j, n) {  // 終点
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }

  double ans = 0.0;

  rep(i, n)
  {
    int size = 0;
    rep(j, n) if (d[j][i] < INF) size++;
    ans += 1.0 / size;
  }

  printf("%.10lf\n", ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}