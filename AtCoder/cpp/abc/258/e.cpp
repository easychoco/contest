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
  loop[now] = 0;
  repi (i, 1, sz + 2) {
    now = next(now);
    if (loop[now] == -1) loop[now] = i;
    else return P(now, i - loop[now]);
  }
  return P(-1, 0);
}

void solve()
{
  ll n, q, x;
  cin >> n >> q >> x;

  vl w(n);
  rep(i, n) cin >> w[i];

  ll sum = accumulate(ALL(w), 0LL);
  // boxes[i] = pair<to, capacity>
  vp boxes(n);
  {
    ll now = (x / sum) * sum;
    ll cnt = (x / sum) * n;

    ll ti = 0;
    rep(i, n)
    {
      // debug(">", now);
      while (now < x)
      {
        now += w[ti];
        cnt++;
        ti++;
        ti %= n;
      }
      // debug("->", now, cnt);
      boxes[i] = make_pair(ti, cnt);
      now -= w[i];
      cnt--;
      // debug("-->", now);
    }
  }

  auto next = [&](ll idx) { return boxes[idx].first; };
  auto [si, sz] = detect_cycle_loop<P>(boxes, next);

  ll st_dist = -10;
  vp memo(n);
  memo[0] = boxes[0];
  if (si == 0) st_dist = 0;
  repi(i, 1, n)
  {
    ll now = memo[i - 1].first;
    if (now == si && st_dist == -10) st_dist = i;
    memo[i] = boxes[now];
  }

  rep(_, q)
  {
    ll k;
    cin >> k;
    k--;
    if (k > st_dist)
    {
      k = st_dist + (k - st_dist) % sz;
    }
    print(memo[k].second);
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}
