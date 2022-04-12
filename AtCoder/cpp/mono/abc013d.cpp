#include <bits/stdc++.h>
#include <atcoder/all>

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
#define rrepi(i, n, a) for (ll i = (n); i >= (a); --i)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
#define eb emplace_back

using namespace std;
using namespace atcoder;
using vb = vector<bool>;
using vvb = vector<vb>;
using ll = int_fast64_t;
using vl = vector<ll>;
using vvl = vector<vl>;
using P = pair<ll, ll>;
using vp = vector<P>;
using vvp = vector<vp>;
using T = tuple<ll, ll, ll>;
using vt = vector<T>;
const ll INF = 1LL << 60;
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
inline void printvp(T &p)
{
  for (auto [a, b] : p)
    print(a, b);
}
template <class T>
inline void printvt(T &t)
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
  ll n, m, d;
  cin >> n >> m >> d;
  vl a(m);
  rep(i, m) cin >> a[i];

  vvl tr(40, vl(n, 0));
  iota(ALL(tr[0]), 0LL);
  rrep(i, m - 1)
  {
    swap(tr[0][a[i] - 1], tr[0][a[i]]);
  }

  ll cnt = 1;
  ll loop_cnt = 0;
  while (cnt <= d)
  {
    rep(i, n)
    {
      tr[loop_cnt + 1][i] = tr[loop_cnt][tr[loop_cnt][i]];
    }
    cnt *= 2LL;
    loop_cnt++;
  }

  vl ans(n);
  iota(ALL(ans), 0LL);
  loop_cnt = 0;
  while (d > 0)
  {
    if (d & 1)
    {
      rep(i, n) ans[i] = tr[loop_cnt][ans[i]];
    }
    d >>= 1;
    loop_cnt++;
  }
  rep(i, n) cout << (ans[i] + 1) << endl;
}

int main()
{
  fastio;
  solve();

  return 0;
}
