#include <bits/stdc++.h>
#include <atcoder/all>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i=(a);i<(ll)(n);++i)
#define repe(i,n) repie(i,0,n)
#define repie(i,a,n) for(ll i=(a);i<=(ll)(n);++i)
#define rrep(i,n) rrepi(i,n,0)
#define rrepi(i,n,a) for(ll i=(n);i>=(ll)(a);--i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define pb push_back
#define eb emplace_back

using namespace std;
using namespace atcoder;
using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vs = vector<string>;
using vl = vector<ll>;
using vvl = vector<vl>;
using P = pair<ll, ll>;
using vp = vector<P>;
using vvp = vector<vp>;
using T = tuple<ll, ll, ll>;
using vt = vector<T>;
const ll INF = 1LL << 60;
void YN(bool a, string whenT="Yes", string whenF="No") { cout << (a ? whenT : whenF) << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
void print() { cout << endl; }
template <class T>
void print(T &&t){ cout << t << endl; }
template <class Head, class... Tail>
void print(Head &&head, Tail &&...tail){ cout << head << " "; print(std::forward<Tail>(tail)...); }
void printd(double d) { cout << std::fixed << setprecision(13) << d << endl; }
template <class T>
inline void printv(T &v){ for (auto a : v) print(a); }
template <class T>
inline void printp(T &p){ for (auto [a, b] : p) print(a, b); }
template <class T>
inline void printt(T &t){ for (auto [a, b, c] : t) print(a, b, c); }
void debug() { cerr << endl; }
template <class Head, class... Tail>
void debug(Head&& head, Tail&&... tail){ cerr << head << " "; debug(std::forward<Tail>(tail)...); }

void solve()
{
  ll n;
  cin >> n;
  vl v, w;
  ll sum = 0;
  rep(i, n)
  {
    ll x, y, z;
    cin >> x >> y >> z;
    sum += z;

    ll needs = max((x + y + 1) / 2 - x, 0LL);
    v.pb(z);
    w.pb(needs);
  }

  if (n == 1)
  {
    print(w[0]);
    return;
  }

  // dp[i][j] = i番目まで見て、価値がjの時の最小重さ
  vector< vector<ll> > dp(n + 1, vector<ll>(sum + 1, INF));
  dp[0][0] = 0;
  rep(i, n) rep(j, sum)
  {
    if (j - v[i] >= 0) dp[i + 1][j] = min(dp[i][j - v[i]] + w[i], dp[i][j]);
    else dp[i + 1][j] = dp[i][j];
  }

  ll ans = INF;
  repie(i, sum / 2 + 1, sum) {
    chmin (ans, dp[n][i]);
  }
  print(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}
