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
void YN(bool a, string whenT="Yes", string whenF="No") { cout << (a ? whenT : whenF) << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
void print() { cout << endl; }
template <class Head, class... Tail>
void print(Head &&head, Tail &&...tail){ cout << head << " "; print(std::forward<Tail>(tail)...); }
void printd(double d) { cout << std::fixed << setprecision(13) << d << endl; }
template <class T>
inline void printv(T &v){ for (auto a : v) print(a); }
template <class T>
inline void printvp(T &p){ for (auto [a, b] : p) print(a, b); }
template <class T>
inline void printvt(T &t){ for (auto [a, b, c] : t) print(a, b, c); }
void debug() { cerr << endl; }
template <class Head, class... Tail>
void debug(Head&& head, Tail&&... tail){ cerr << head << " "; debug(std::forward<Tail>(tail)...); }

/**
 * @brief ループの始点と周期を求める
 * 
 * @tparam T target の型
 * @param target 検証対象の vector
 * @param next ひとつ進める function / target の index をもらって、次の index を返す
 * @param first_index 検証を始める index
 * @return pair<start_index, loop_size>
 */
template <class T>
pair<ll, ll> detect_cycle_loop(
  const vector<T>& target,
  function<ll(ll)> next,
  ll first_index = 0
) {
  ll sz = target.size();
  vl loop(sz, -1);
  ll now = first_index;
  rep (i, sz + 1) {
    now = next(now);
    if (loop[now] == -1) loop[now] = i;
    else return P(now, i - loop[now]);
  }
  return P(-1, 0);
}

/**
 * @brief ループの始点と周期と累計スコアを計算する
 * ```cpp
  // https://atcoder.jp/contests/abc241/tasks/abc241_e
  auto next = [&](ll acc, ll now){ return acc % n; };
  auto calc = [&](ll acc, ll now){ return acc + a[now]; };
  auto [_1, _2, t] = detect_cycle_loop_acc<ll, ll>(a, next, calc, k);
 * ```
 * 
 * @tparam T target の型
 * @tparam U score の型 / ll か mint の想定
 * @param target 検証対象の vector
 * @param next ひとつ進める function
 * @param calc 値を計算する function
 * @param loop_count 繰り返す回数
 * @param first_index 検証の開始位置
 * @return tuple<start_index, loop_size, score>
 */
template <class T, class U>
tuple<ll, ll, U> detect_cycle_loop_acc(
  const vector<T>& target,
  function<ll(U, ll)> next,
  function<U(U, ll)> calc,
  ll loop_count,
  ll first_index = 0
) {
  ll sz = target.size();
  ll now = first_index;
  U acc = 0; // 累計値 : accumulate

  // ループ数が小さい時は直接やる
  if (loop_count <= sz) {
    rep(i, loop_count) {
      acc = calc(acc, now);
      now = next(acc, now);
    }
    return make_tuple(-1, -1, acc);
  }

  // P(最後に来た時の loop, 最後に来た時のスコア)
  const pair<ll, U> init = P(-1, 0);
  vector<pair<ll, U>> loop(sz, init);
  rep(i, sz + 1) {
    acc = calc(acc, now);
    now = next(acc, now);

    if (loop[now] == init) {
      // 初めてくるものなら記録する
      loop[now] = make_pair(i, acc);
      continue;
    }

    // ループした
    auto [li, lx] = loop[now];
    ll loop_size = i - li;   // 周期
    U loop_score = 0; // acc - lx; // 1周期のスコア
    acc += ((loop_count - i - 1) / loop_size) * loop_score;

    // 残りのループ回数
    rep(_, (loop_count - i - 1) % loop_size) {
      acc = calc(acc, now);
      now = next(acc, now);
    }
    return make_tuple(li, loop_size, acc);
  }
  return make_tuple(-1, -1, 0);
}

void solve()
{
  // https://atcoder.jp/contests/abc179/tasks/abc179_e
  // ll n, x, m;
  // cin >> n >> x >> m;

  // vl target(m, 0);
  // auto next = [&](ll acc, ll now){ return now * now % m; };
  // auto calc = [&](ll acc, ll now){ return acc + now; };
  // auto [_1, _2, t] = detect_cycle_loop_acc<ll, ll>(target, next, calc, n, x);
  // print(t);


  // https://atcoder.jp/contests/abc167/tasks/abc167_d
  // ll n, k;
  // cin >> n >> k;
  // vl a(n);
  // rep(i, n) cin >> a[i];

  // auto next = [&](ll acc, ll now){return a[now] - 1; };
  // auto calc = [&](ll acc, ll now){return now + 1; };
  // auto [_1, _2, t] = detect_cycle_loop_acc<ll, ll>(a, next, calc, k + 1);
  // print(t);

}

int main()
{
  fastio;
  solve();

  return 0;
}
