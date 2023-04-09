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

  // i 回投げた時の最大値の期待値
  vector<double> ex(n + 1, 0.0);

  // n 回投げた時に m より大きい数が出る確率
  auto f1 = [&](ll n, ll m)
  {
    return 1.0 - pow(m / 6.0, n);
  };

  // n 回なげて
  auto f2 = [&](ll n, ll m)
  {

  };

  // 6 が出たら終わり
  // n 回なげていちどでも 6　が出る確率
  double d6 = f1(n, 5);

  // i が出た時に f1(n, i) が 0.5以上ならもう一度投げる

  // dp[i][j] = i 回なげてスコアが j になる確率
  vector< vector<double> > dp(n + 1, vector<double>(6, 0.0));
  rep(i, 6) dp[1][i] = 1 / 6.0;

  // i 回なげて
  repi(i, 1, n)
  {
    dp[i + 1][5] = dp[i][5];

    double sum = 0.0;
    repie(j, 1, 5)
    {
      double p = f1(n - i, 1);
      if (p >= 0.5)
      {
        sum += dp[i][j] / 6.0;
        dp[i + 1][5] += dp[i][j] / 6.0;
      }
    }
    rep(j, 5) dp[i + 1][j] = sum;
  }

  double ans = 0.0;
  rep(i, 6) ans += (i + 1) * dp[n][i];
  print(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}
