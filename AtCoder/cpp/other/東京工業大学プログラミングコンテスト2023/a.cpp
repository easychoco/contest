#include <bits/stdc++.h>

#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL);
#define endl "\n"
#define rep(i, n) repi(i, 0, n)
#define repi(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define repe(i, n) repie(i, 0, n)
#define repie(i, a, n) for (ll i = (a); i <= (ll)(n); ++i)
#define rrep(i, n) rrepi(i, n, 0)
#define rrepi(i, n, a) for (ll i = (n); i >= (ll)(a); --i)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
#define eb emplace_back

using namespace std;
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
const ll MOD = 998244353LL;
void YN(bool a, string whenT = "Yes", string whenF = "No") { cout << (a ? whenT : whenF) << endl; }
template <class T>
inline bool chmax(T &a, T b)
{
  if (a < b)
  {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool chmin(T &a, T b)
{
  if (a > b)
  {
    a = b;
    return true;
  }
  return false;
}
void print() { cout << endl; }
template <class T>
void print(T &&t) { cout << t << endl; }
template <class Head, class... Tail>
void print(Head &&head, Tail &&...tail)
{
  cout << head << " ";
  print(std::forward<Tail>(tail)...);
}
void printd(double d) { cout << std::fixed << setprecision(13) << d << endl; }
template <class T>
inline void printv(T &v)
{
  for (auto a : v)
    print(a);
}
template <class T>
inline void printp(T &p)
{
  for (auto [a, b] : p)
    print(a, b);
}
template <class T>
inline void printt(T &t)
{
  for (auto [a, b, c] : t)
    print(a, b, c);
}
void debug() { cerr << endl; }
template <class Head, class... Tail>
void debug(Head &&head, Tail &&...tail)
{
  cerr << head << " ";
  debug(std::forward<Tail>(tail)...);
}

void solve()
{
  ll n;
  cin >> n;

  ll ans = 0;

  // dp[i] = i 番目に人がいくための最小手順
  vl dp(n, 0);
  repi(i, 1, n)
  {
    dp[i] = (dp[i - 1] * 2 + 1) % MOD;
    ans += dp[i];
    ans %= MOD;
  }
  print(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}
