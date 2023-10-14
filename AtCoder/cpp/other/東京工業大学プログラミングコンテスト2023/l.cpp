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
  vs s(4);
  cin >> n;
  rep(i, 4) cin >> s[i];

  if ( // 部分点ねらい
      s[0].length() > 50 ||
      s[1].length() > 50 ||
      s[2].length() > 50 ||
      s[3].length() > 50)
  {
    print(-1);
    return;
  }

  /*
    TTPC
    TLE
    P
    AC
  */

  // 1文字目が T になる年は 1,2,5,6,9,10, ...
  // 2文字目が T になる年は 1,3,6,9,12, ...
  // 3文字目が P になる年は 1,2,3,4,5,6,7,8,9,10, ...
  // 4文字目が C になる年は 2,4,6,8,10, ...

  ll sz0 = s[0].length();
  ll sz1 = s[1].length();
  ll sz2 = s[2].length();
  ll sz3 = s[3].length();
  ll prod = sz0 * sz1 * sz2 * sz3;

  vl ok(0);
  rep(i, prod)
  {
    string name = "----";
    name[0] = s[0][i % sz0];
    name[1] = s[1][i % sz1];
    name[2] = s[2][i % sz2];
    name[3] = s[3][i % sz3];
    if (name == "TTPC")
    {
      ok.pb(i + 1);
    }
  }

  ll count = 0;
  ll ans = -1;
  rep(i, n)
  {
    for (auto &v : ok)
    {
      ans = prod * i + v;
      count++;
      if (count == n)
      {
        print(ans);
        return;
      }
    }
  }
  print(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}
