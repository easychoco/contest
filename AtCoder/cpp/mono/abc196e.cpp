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
void YN(bool a) { cout << (a ? "Yes" : "No") << endl; }
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
void show() { cout << endl; }
template <class Head, class... Tail>
void show(Head &&head, Tail &&...tail)
{
  cout << head << " ";
  show(std::forward<Tail>(tail)...);
}
void showd(double d) { cout << std::fixed << setprecision(13) << d << endl; }
template <class T>
inline void showall(T &a)
{
  for (auto v : a)
    cout << v << " ";
  cout << endl;
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
  vl a(n), t(n);
  rep(i, n) cin >> a[i] >> t[i];

  ll q;
  cin >> q;
  vl x(q);
  rep(i, q) cin >> x[i];

  auto filter = [&](ll arg) -> ll
  {
    rep(i, n)
    {
      if (t[i] == 1)
      {
        arg += a[i];
      }
      else if (t[i] == 2)
      {
        arg = max(arg, a[i]);
      }
      else
      {
        arg = min(arg, a[i]);
      }
    }
    return arg;
  };

  ll min_v = filter(-1'000'000'000LL);
  ll max_v = filter(1'000'000'000LL);
  auto min_f = [&](ll arg) -> bool
  {
    return filter(arg) > min_v;
  };
  ll min_wa = -1'000'000'001LL, min_ac = 1'000'000'000LL;
  while (min_ac - min_wa > 1)
  {
    ll wj = (min_ac + min_wa) / 2;
    if (min_f(wj))
      min_ac = wj;
    else
      min_wa = wj;
  }

  auto max_f = [&](ll arg) -> bool
  {
    return filter(arg) < max_v;
  };
  ll max_ac = -1'000'000'000LL, max_wa = 1'000'000'001LL;
  while (max_wa - max_ac > 1)
  {
    ll wj = (max_ac + max_wa) / 2;
    if (max_f(wj))
      max_ac = wj;
    else
      max_wa = wj;
  }

  if (min_ac == max_ac)
  {
    rep(i, q) show(min_v);
    return;
  }

  debug(min_wa, min_ac);
  debug(max_wa, max_ac);

  ll min_ac_v = filter(min_wa);
  ll max_ac_v = filter(max_wa);

  debug(min_ac_v, max_ac_v);
  rep(i, q)
  {
    if (x[i] < min_ac)
      show(min_ac_v);
    else if (x[i] > max_ac)
      show(max_ac_v);
    else
      show(x[i] + min_ac_v - min_wa);
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}
