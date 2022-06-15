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

// 座標圧縮 O (N log N)
// 破壊的なので注意
// 戻り値は重複を削除 ( sort & unique ) した vector
template <typename T>
vector<T> compress(vector<T> &vec)
{
  vector<T> ret = vec;

  // 重複削除
  sort(ALL(ret));
  ret.erase(unique(ALL(ret)), ret.end());

  // 各要素ごとに二分探索で位置を求める
  rep (i, vec.size())
  {
    vec[i] = lower_bound(ALL(ret), vec[i]) - ret.begin();
  }

  return ret;
}

ll op(ll a, ll b) {
  return max(a, b);
}

ll e() {
  return 0LL;
}

void solve()
{
  ll x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  ll n;
  cin >> n;
  vl x(n), y(n);

  // x1 < x2 かつ
  // y1 < y2 にする

  if (x1 > x2)
  {
    swap(x1, x2);
    swap(y1, y2);
  }
  ll sign = 1;
  if (y1 > y2)
  {
    sign = -1;
    swap(y1, y2);
  }

  bool isx = false;
  bool isy = false;
  if (x1 == x2)
  {
    isx = true;
  }
  if (y1 == y2)
  {
    isy = true;
  }

  bool out_of_range = false;

  rep(i, n)
  {
    cin >> x[i] >> y[i];
    if (isx && x1 == x[i])
    {
      if (y1 < y[i] && y[i] < y2)
      {
        printd((y2 - y1) * 100.0 + 11.415926535897938);
      }
      else
      {
        printd((y2 - y1) * 100.0);
      }
      return;
    }
    if (isy && y1 == y[i])
    {
      if (x1 < x[i] && x[i] < x2)
      {
        printd((x2 - x1) * 100.0 + 11.415926535897938);
      }
      else
      {
        printd((x2 - x1) * 100.0);
      }
      return;
    }

    if (!(
      x1 <= x[i] && x[i] <= x2 &&
      y1 <= y[i] && y[i] <= y2
    ))
    {
      x[i] = y[i] = INF;
      out_of_range = true;
    }
    else
    {
      y[i] *= sign;
    }
  }

  const ll BIG_NUM = INF - 10;

  n++;
  x.pb(-BIG_NUM);
  y.pb(-BIG_NUM);

  n++;
  x.pb(BIG_NUM);
  y.pb(BIG_NUM);

  compress(x);
  compress(y);

  vp p(n);
  rep(i, n)
  {
    p[i] = P(x[i], y[i]);
  }

  sort(ALL(p));
  p.erase(unique(ALL(p)), p.end());
  n = p.size() - out_of_range;

  segtree<ll, op, e> seg(n);
  vl ans(n);
  rep(i, n)
  {
    auto [px, py] = p[i];
    ans[py] = seg.prod(0, py) + 1;
    seg.set(py, ans[py]);
  }
  debug("n is", n, "num is", seg.prod(0, n) - 2);
  ll count = seg.prod(0, n) - 2;
  double ansd = (abs(x1 - x2) + abs(y1 - y2)) * 100.0;

  ll xc = x2 - x1 + 1;
  ll yc = y2 - y1 + 1;
  if (count == n - 2 && count > 0 && (xc == count || yc == count))
  {
    ansd += (count - 1) * (5.0 * M_PI - 20.0) + 11.415926535897938;
  }
  else
  {
    ansd += count * (5.0 * M_PI - 20.0);
  }
  printd(ansd);
}

int main()
{
  fastio;
  solve();

  return 0;
}
