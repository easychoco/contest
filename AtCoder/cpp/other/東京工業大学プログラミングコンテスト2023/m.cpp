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
#define rrepi(i, n, a) for (ll i = (n); i >= (ll)(a); --i)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
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

// 最大公約数 : 3,4 ->  1
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

// 最小公倍数 : 3,4 -> 12
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

void solve()
{
  ll n;
  cin >> n;
  vl p(n);
  vl q(n);

  ll u = 1;

  rep(i, n)
  {
    ll pi, qi;
    cin >> pi >> qi;
    if (qi > 30)
    { // 部分点ねらい
      print(0);
      return;
    }

    p[i] = pi;
    q[i] = qi;
    u = lcm(u, qi);
  }

  rep(i, n) p[i] *= u / q[i];

  // zero-sum-range
  vl a(p);
  rep(i, n - 1) a[i + 1] += a[i];

  map<ll, ll> mp;
  mp[0] = 1;
  rep(i, n) mp[a[i] % u]++;

  ll ans = 0;
  for (auto v : mp)
  {
    ll val = v.second;
    ans += val * (val - 1) / 2;
  }

  print(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}
