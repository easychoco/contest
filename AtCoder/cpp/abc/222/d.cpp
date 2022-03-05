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

using mint = modint998244353;

void solve()
{
  ll n;
  cin >> n;
  vector<ll> a(n), b(n);
  rep(i, n)
  {
    cin >> a[i];
  }
  rep(i, n) cin >> b[i];

  // dp[i][j] = 数列C の i 番めが j で終わるときの組み合わせ数
  vector< vector<mint> > dp(n, vector<mint>(3010, 0));
  repie(j, a[0], b[0]) dp[0][j] = 1;
  rep(j, 3000) dp[0][j + 1] += dp[0][j];

  repi(i, 1, n)
  {
    repie(j, a[i], b[i]) dp[i][j] = dp[i - 1][j];
    rep(j, 3000) dp[i][j + 1] += dp[i][j];
  }
  show(dp[n - 1][b[n - 1]].val());
}

int main()
{
  fastio;
  solve();

  return 0;
}
