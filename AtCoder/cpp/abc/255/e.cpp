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
  ll n, m;
  cin >> n >> m;
  vl s(n - 1), x(m), b(n, 0);
  rep(i, n - 1) cin >> s[i];
  rep(i, m) cin >> x[i];

  // s[0] = a[0] + a[1]
  // s[1] = a[1] + a[2]
  // s[2] = a[2] + a[3]
  // s[3] = a[3] + a[4]
  // a[1] = s[0] - a[0] = s[0] - a[0] -> b[0] - a[0] = x
  // a[2] = s[1] - a[1] = s[1] - s[0] + a[0] -> b[1] + a[0] = x
  // a[3] = s[2] - a[2] = s[2] - s[1] + s[0] - a[0] -> b[2] - a[0] = x
  // a[4] = s[3] - a[3] = s[3] - s[2] + s[1] - s[0] + a[0] -> b[3] + a[0] = x
  // ->
  // a[1] = b[0] - a[0] = x
  // a[2] = b[1] + a[0] = x
  // a[3] = b[2] - a[0] = x
  // a[4] = b[3] + a[0] = x

  unordered_map<ll, ll> hist;

  // a[0] = 0 としたときの差
  rep(i, n - 1)
  {
    b[i + 1] = s[i] - b[i];
  }

  rep(i, n)
  rep(j, m)
  {
    // a[0] を a0 にすると、a[i] が x[j] になる

    ll a0 = x[j] - b[i];
    // このときは -a[0] になっているので a[0] にもどす
    if ((i + 1) & 1) a0 *= -1;

    hist[a0]++;
  }

  ll ans = 0;
  for (auto [_k, v] : hist) chmax(ans, v);
  print(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}
