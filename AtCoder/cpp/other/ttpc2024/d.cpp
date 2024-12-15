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

bool isOdd(ll v) { return (v & 1) == 1; }

void solve()
{
  ll n, q;
  cin >> n >> q;

  if (q != 1) {
    return;
  }

  vl a(n), b(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];

  ll sum_0 = 0; // 初期値が偶数のときに適用される
  ll sum_1 = 0; // 初期値が奇数のときに適用される
  ll now_0 = 0;
  ll now_1 = 1;

  rep(i, n) {
    if (now_0 & 1) {
      sum_0 ^= a[i];
      now_0 ^= a[i];
    } else {
      sum_0 ^= b[i];
      now_0 ^= b[i];
    }

    if (now_1 & 1) {
      sum_1 ^= a[i];
      now_1 ^= a[i];
    } else {
      sum_1 ^= b[i];
      now_1 ^= b[i];
    }
  }

  ll d1, v, d2, d3;
  cin >> d1 >> v >> d2 >> d3;

  ll cd1(INF), cd2(INF), cd3(INF), cd4(INF);
  if (isOdd(v)) {
    // 奇数を作る
    if (!isOdd(v ^ sum_0) && isOdd(sum_0)) {
      cd1 = v ^ sum_0;
    }
    if (isOdd(v ^ sum_1) && !isOdd(sum_1)) {
      cd2 = v ^ sum_1;
    }
  } else {
    // 偶数を作る
    if (!isOdd(v ^ sum_0) && !isOdd(sum_0)) {
      cd3 = v ^ sum_0;
    }
    if (isOdd(v ^ sum_1) && isOdd(sum_1)) {
      cd4 = v ^ sum_1;
    }
  }

  ll ans = min({ cd1, cd2, cd3, cd4 });
  if (ans == INF) ans = -1;
  print(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}
