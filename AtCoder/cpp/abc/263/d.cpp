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

// Segment Tree
// segment_tree / SegmentTree
// セグメント木
// https://www.creativ.xyz/segment-tree-entrance-999/
// 使用関数の引数は全て1-index
// query() は半開区間
// ===================  問題ごとに設定 ====================
// !!使う前に init() を呼ぶ!!
const int N = 1 << 20;              // 葉の数、2の累乗数
const ll E = 0;                     // 演算での単位元
ll op(ll a, ll b) { return max(a, b); } // 使用する演算、可換
// =======================================================
ll node[N * 2 + 1];
void init(){
  for(int i = 0; i < N * 2 + 1; ++i) node[i] = E;
}
ll get(int i) { return node[i + N - 1]; }
void update(int i, ll x){ // i 番目の葉の値を x に変える
  i += N - 1; // i 番目の葉のノード番号
  node[i] = x;
  while (i > 0) {
    i = (i - 1) / 2; // ノード i の親ノードの番号に変える
    node[i] = op(node[i * 2 + 1], node[i * 2 + 2]); // 左右の子の値を計算しなおす
  }
}
ll query(int a, int b, int k = 0, int l = 0, int r = N){
  // [a, b) の区間に対するクエリについてノード k （区間 [l, r) 担当）が答える
  if (r <= a || b <= l) return E; // 区間が被らない場合は単位元を返す
  if (a <= l && r <= b) return node[k]; // ノード k の担当範囲がクエリ区間 [a, b) に完全に含まれる
  // 一部だけ範囲が被る場合は左右の子に委託する
  ll c1 = query(a, b, 2 * k + 1, l, (l + r) / 2); // 左の子に値を聞く
  ll c2 = query(a, b, 2 * k + 2, (l + r) / 2, r); // 右の子に値を聞く
  return op(c1, c2);
}
// Segment Tree ここまで

void solve()
{
  ll n, l, r;
  cin >> n >> l >> r;
  vl a(n);
  rep(i, n) cin >> a[i];

  init();
  vl b(n, 0);
  rep(i, n)
  {
    b[i] = a[i] - l;
    if (i > 0) b[i] += b[i - 1];
    update(i + 1, b[i]);
  }

  // r をずらしながら l を評価する
  ll sum = 0;
  ll ans = 0;
  rrep(i, n)
  {
    if (i < n) sum += a[i];

    // i から n - 1 までを r にする
    ll rs = sum - (n - i) * r;
    ll score = rs + query(1, i + 1);
    chmax(ans, score);
  }

  ll acc = accumulate(ALL(a), 0LL);
  print(acc - ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}
