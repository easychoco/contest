// https://github.com/atcoder/live_library
// https://qiita.com/kawa-Kotaro/items/782bc31b64e4ee13649a
// https://atcoder.github.io/ac-library/production/document_ja/

// g++ --std=gnu++17 -I ~/pg/ac-library -Wall -Werror -O2

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

using namespace std;
using namespace atcoder;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using P = pair<ll, ll>;
const ll INF = 1LL << 60;
void YN(bool a) { cout << (a ? "Yes" : "No") << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
void show(){ cout << endl; }
template <class Head, class... Tail>
void show(Head&& head, Tail&&... tail){ cout << head << " "; show(std::forward<Tail>(tail)...); }
template<class T> inline void showall(T& a) { for(auto v:a) cout<<v<<" "; cout<<endl; }

string getIntStr(ll pow)
{ // 入力を文字列で受け取って、10^pow 倍して整数部分を返す。小数の丸め誤差対策。
  string in;
  cin >> in;
  string ret = "";

  if (pow < 0)
  {
    reverse(ALL(in));
    for(int i = 1; i < (int)in.length(); ++i)
    {
      if (in[i] == '.')
      {
        swap(in[i], in[i + 1]);
        pow++;
        if (pow == 0) break;
      }
    }
    reverse(ALL(in));
  }

  if (pow == 0)
  {
    rep(i, in.length())
    {
      if (in[i] != '.') ret += in[i];
      else break;
    }
    return ret;
  }

  for(int i = 0; i < pow; ++i) in += '0';
  for(int i = 1; i < (int)in.length(); ++i)
  {
    if (in[i] == '.')
    {
      swap(in[i], in[i + 1]);
      ret += in[i];
      pow--;
      if (pow <= 0) break;
    }
  }
  return ret;
}

void tip_div()
{
  ll a ,b;
  // a / b の切り上げ
  (a - 1) / b + 1;

  // a / b の四捨五入
  (a + b / 2) / b;
}

// 最大公約数 : 3,4 ->  1
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

// 最小公倍数 : 3,4 -> 12
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

// https://www.youtube.com/watch?v=hY2FicqnAcc
// 拡張GCD : O(log b)
// a と b の gcd を求める
// ax + by = gcd となるx, yを求める
// b を mod にすると、mod が素数でないときも逆元を求められる
tuple<ll, ll, ll> extgcd(ll a, ll b) {
  if (b == 0) return make_tuple(a, 1LL, 0LL);
  ll g, x, y;
  tie(g, x, y) = extgcd(b, a % b);
  return make_tuple(g, y, x - (a / b) * y);
}

// 素数判定
bool isPrime(ll a) {
  if (a == 1) return false;
  for (ll i = 2; i * i <= a; i++) {
    if(a % i == 0) return false;
  }
  return true;
}

// a^n % mod を計算する O(log n)
ll powmod(ll a, ll n, ll mod) {
  ll ret = 1;
  while (n > 0) {
    if (n % 2 == 1) { ret = ret * a % mod; }
    a = a * a % mod;
    n /= 2;
  }
  return ret;
}

// nCr % mod を計算する O(r)
ll combmod(ll n, ll r, ll mod) {
  ll x = 1, y = 1;
  r = min(n - r, r);
  for(ll i = 0; i < r; ++i) { x = x * (n - i) % mod; }	// 分子
  for(ll i = 1; i <= r; ++i) { y = y * i % mod; }			// 分母
  return x * powmod(y, mod - 2, mod) % mod;	// nCr = (分子) * (分母)^-1 mod M
}

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

// =================================================================================================== //

// 素因数分解
void tip_facotrization()
{
  ll num;
  map<ll, ll> primes;
  ll factor = 2;
  while(factor * factor <= num)
  {
    if (num % factor == 0)
    {
      primes[factor]++;
      num /= factor;
    }
    else ++factor;
  }
  primes[num]++;
}

// 二分探索
// めぐる式
void tip_binary_search()
{
  auto f = [&](ll arg) -> bool
  {
    return arg > 0;
  };
  ll ac = 0, wa = 1'000'000'000LL;
  while(wa - ac > 1)
  {
    ll wj = (ac + wa) / 2;
    if ( f(wj) ) ac = wj;
    else wa = wj;
  }
}

// 二次元累積和
// 二次元いもす法 imos
// O (X * Y)
void accumulate_sum_2D()
{
  ll h, w, q;
  vector<vector<ll>> a(h, vector<ll>(w, 0));
  vector<vector<ll>> sum(h + 1, vector<ll>(w + 1, 0));

  // いもすはこれ
  rep(i, q)
  {
    ll lx, ly, rx, ry;
    cin >> lx >> ly >> rx >> ry;
    a[ly][lx] += 1;
    a[ry][lx] += -1;
    a[ly][rx] += -1;
    a[ry][rx] += 1;
    /* // どっちか
    a[ly][lx] += 1;
    a[ry + 1][lx] += -1;
    a[ly][rx + 1] += -1;
    a[ry + 1][rx + 1] += 1;
    */
  }

  rep(y, h) rep(x, w) sum[y + 1][x + 1] = sum[y][x + 1] + sum[y + 1][x] - sum[y][x] + (a[y][x]);

  ll ky = 3, kx = 4;
  rep(y, h - ky + 1) rep(x, w - kx + 1)
  {
    // [x1, x2) x [y1, y2) の区間の和を求める
    ll y1, y2, x1, x2;
    y1 = y;
    y2 = y + ky;
    x1 = x;
    x2 = x + kx;
    ll sum_2D = sum[y2][x2] - sum[y1][x2] - sum[y2][x1] + sum[y1][x1];
  }
}

// クラスカル法
// 最小全域木問題
// [UnionFind木] を貼る
void tip_kruskal()
{
  // ======================================
  // このクラスはいらない
  // コンパイルを通すためのダミークラス
  class UnionFind{ 
    public: UnionFind(ll a){}
    bool same(ll a, ll b){ return true; }
    void unite(ll a, ll b){}
  };
  // ここまでいらない
  // ======================================

  ll n = 1;
  //     tuple<cost, from, to>
  vector<tuple<ll, ll, ll> > G;
  UnionFind uf(n);
  
  rep(i, n)
  {
    ll cost, from, to;
    G.emplace_back(cost, from, to);
  }
  sort(ALL(G));

  ll dist_sum = 0;
  ll edge_cnt = 0;
  for(const auto& edge : G)
  {
    ll cost, from, to;
    tie(cost, from, to) = edge;
    if (!uf.same(from, to))
    {
      uf.unite(from, to);
      dist_sum += cost;
      ++edge_cnt;
    }
  }
}


// ワーシャルフロイド法
// 全点対最短経路 O(n^3)
void tip_warshall_floyd(int n) {
  const ll INF = 1'001'001'001'001;
  const int n = 300;
  vector< vector<ll> > dist(n, vector<ll>(n, INF));
  rep(i, n) rep(j, n) dist[i][j] = INF;
  rep(i, n) dist[i][i] = 0;

  rep (k, n){       // 経由する頂点
    rep (i, n) {    // 始点
      rep (j, n) {  // 終点
        chmin(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
}

// ベルマンフォード法
// 単一始点最短経路問題 O(VE)
void tip_bellman_ford()
{
  // 重みがすべて正値のときはダイクストラ法を使う
  ll n, m, u, v, w;
  cin >> n >> m;
  //     tuple<from, to, cost>
  vector<tuple<ll, ll, ll>> G(m);
  rep(i, m)
  {
    cin >> u >> v >> w;
    u--; v--;
    G[i] = make_tuple(u, v, w);
  }

  const ll INF = 1LL << 60;
  vector<ll> d(n, INF);
  d[0] = 0;

  rep(i, n)
  {
    rep(j, m)
    {
      ll from, to, cost;
      tie(from, to, cost) = G[j];
      if (chmin(d[to], d[from] + cost))
      {
        if (i == n - 1) //負閉路検出
        {
          cout << "negative loop" << endl;
          break;
        }
      }
    }
  }
}

// Dijkstra法 ダイクストラ法
// 単一始点最短経路問題 O(E log V)

void dijkstra()
{
  // 重みに負値があるときはベルマンフォード法を使う

  // w=1(固定長)の時はpriority_queueをqueueにするとO(NlogN)がO(logN)になる
  // 大抵は不要だけどO(NlogN)では厳しいときに
  // 下のtip_graph_bfsも検討
  ll n, m;
  cin >> n >> m;
  // tuple<cost, to>
  vector< vector<tuple<ll, ll>> > G(n);
  rep(i, m)
  {
    ll u, v, w;
    cin >> u >> v >> w;
    u--; v--;
    G[u].emplace_back(w, v);
    G[v].emplace_back(w, u); // 無向グラフの場合
  }

  const ll INF = 1LL << 60;
  vector<ll> d(n, INF);
  d[0] = 0;
  priority_queue<P, vector<P>, greater<P>> que;
  que.push(P(0, 0)); // P(cost, start)
  while (!que.empty())
  {
    P p = que.top();
    que.pop();
    ll now = p.second;
    if (d[now] < p.first) continue;
    for (const auto& edge : G[now])
    {
      ll cost, to;
      tie(cost, to) = edge;
      if (chmin(d[to], d[now] + cost))
      {
        que.push(P(d[to], to));
      }
    }
  }
}

// BFSを使った無向グラフの全探索
void tip_graph_bfs()
{
  ll n, m, a, b;
  cin >> n >> m;
  vector<P> input(m);
  vector< vector<int> > edge(n, vector<int>());
  for(int i = 0; i < m; ++i)
  {
    cin >> a >> b;
    a--; b--;
    input[i] = P(a, b);
    edge[a].emplace_back(b);
    edge[b].emplace_back(a);
  }

  // visited使用
  vector<bool> visited(n, false);
  queue<int> que;
  que.push(0); //初期位置
  while(!que.empty())
  {
    int now = que.front();
    que.pop();
    visited[now] = true;
    for(const auto& to : edge[now])
    {
      if (!visited[to]) //visited使用
      {
        que.push(to);
      }
    }
  }
}

// トポロジカルソート
// topological sort
// O(V + E)
void tip_topological_sort()
{
  ll n, m, u, v;
  cin >> n >> m;
  vector< vector<ll> > edge(n, vector<ll>()); // グラフ・DAG
  vector<ll> deg(n, 0); // 入り次数
  rep(i, m)
  {
    cin >> u >> v;
    u--; v--;
    edge[u].emplace_back(v);
    deg[v]++;
  }

  vector<ll> sorted;
  queue<ll> que;
  rep(i, n) if (deg[i] == 0) que.push(i);
  while(!que.empty())
  {
    ll now = que.front();
    que.pop();
    sorted.emplace_back(now);
    for(const auto& to : edge[now])
    {
      deg[to]--;
      if (deg[to] == 0) que.push(to);
    }
  }
}

// トポロジカルソート(DFS)
// topological sort
// O(V + E)
vector<P> sorted;
vector< vector<ll> > g;
vector<bool> come(100010, false);
void topo_dfs(int prev, int now)
{
  if (come[now]) return;
  come[now] = true;

  for (auto& i: g[now]) topo_dfs(now, i);
  // 帰りがけ順で追加
  sorted.push_back(P(prev, now));
};
void tip_topologicalsort_dfs()
{
  ll n, m;
  cin >> n;
  g = vector< vector<ll> >(n, vector<ll>());
  vector<ll> deg(n, 0); // 入り次数
  rep(i, n)
  {
    ll a, b;
    cin >> a >> b;
    a--; b--;
    g[a].emplace_back(b);
  }
  rep(i, n) topo_dfs(-1, i);
  reverse(ALL(sorted));
}

// SCC : Strongly Connected Component
// 強連結成分分解 きょうれんけつせいぶんぶんかい
// O(V + E)
vector< vector<ll> > graph; // 順方向の
vector< vector<ll> > graph_rev; // 逆方向
vector<ll> group; // 各ノードがどのグループに属するか
vector<ll> seq; // 帰りがけ順の並び
vector<bool> come;
vector<ll> hist; // 各グループに属する

// 1回目の DFS
// 帰りがけ順に記録する
void scc_dfs(ll now)
{
  come[now] = true;
  for (const auto& next : graph[now])
  {
    if (!come[next]) scc_dfs(next);
  }
  seq.emplace_back(now);
}

// 2回目の DFS
// 記録した番号の大きい順にDFSをして、訪れたノードが強連結成分
void scc_dfs_rev(ll now, ll grp)
{
  come[now] = true;
  group[now] = grp;
  hist[grp]++;
  for (const auto& next : graph_rev[now])
  {
    if (!come[next]) scc_dfs_rev(next, grp);
  }
}

void tip_scc()
{
  ll n, m;
  cin >> n >> m;
  graph.resize(n, vector<ll>());
  graph_rev.resize(n, vector<ll>());
  group.resize(n, 0);
  come.resize(n, false);
  hist.resize(n, 0);
  rep(i, m)
  {
    ll a, b;
    cin >> a >> b;
    a--; b--;
    graph[a].emplace_back(b);
    graph_rev[b].emplace_back(a);
  }

  fill(ALL(come), false);
  rep(i, n)
  {
    if (!come[i]) scc_dfs(i);
  }

  fill(ALL(come), false);
  ll grp = 0;
  for(ll i = seq.size() - 1; i >= 0; --i)
  {
    if (!come[seq[i]]) scc_dfs_rev(seq[i], grp++);
  }
}


// =================================================================================================== //

// dynamic programming
void tip_dp()
{
  /*
  // knapsack
  // ナップサック問題
  // dp[i][j] = i個まで見て、重さがjの時の最大価値
  vector< vector<ll> > dp(n + 1, vector<ll>(w + 1, 0));
  rep (i, w) dp[0][i] = 0;
  rep (i, n) rep (j, w)
  {
    if (j >= w[i]) dp[i + 1][j] = max(dp[i][j - w[i]] + v[i], dp[i][j]);
    else dp[i+1][j] = dp[i][j];
  }
  cout << dp[n][w];

  // knapsack
  // ナップサック問題
  // dp[i][j] = i個まで見て、重さがjの時の最大価値
  vector< vector<ll> > dp(n + 1, vector<ll>(w + max_weight, 0));
  rep(i, n) rep(x, w + 1)
  {
    chmax(dp[i + 1][x + w[i]], dp[i][x] + v[i]);
    chmax(dp[i + 1][x], dp[i][x]);
  }
  cout << dp[n][w];

  // knapsack
  // ナップサック問題
  const ll INF = 1LL << 60;
  // dp[i][j] = i番目まで見て、価値がjの時の最小重さ
  vector< vector<ll> > dp(n + 1, vector<ll>(Vsum + 1, INF));
  dp[0][0] = 0;
  rep(i, n) rep(j, Vsum)
  {
    if (j - v[i] >= 0) dp[i + 1][j] = min(dp[i][j - v[i]] + w[i], dp[i][j]);
    else dp[i + 1][j] = dp[i][j];
  }
  ll ans = 0;
  for(int i = Vsum; i >= 0; --i) {
    if (dp[n][i] <= weight) {
      ans = i;
      break;
    }
  }

  // tsp
  // traveling salesman
  // 巡回セールスマン問題
  const ll INF = 1LL << 60;
  // dp[i][j] = いまjにいて、i(mask)の街に訪れているときのコストの最小値
  vector< vector<ll> > dp(1<<n, vector<ll>(n, INF));

  // 開始地点は0固定
  repi(i, 1, n) dp[1<<i][i] = dist[0][i];

  // 全地点開始なら
  // rep(i, n) dp[1 << i][i] = 1;

  rep(mask, 1<<n) rep(now, n)
  {
    if (1 << now & mask) rep(next, n)
    {
      if (1 << next & mask) continue;
      chmin(dp[mask | (1<<next)][next], dp[mask][now] + dist[now][next]);
    }
  }
  cout << dp[(1 << n) - 1][0];

  // 次のようにすれば、元の位置に戻らない場合とかにも対応可能
  // repi(i, 1, n) dp[((1<<n) - 1) ^ 1][i]
  */
}

void tip_mex()
{
  // https://atcoder.jp/contests/abc194/tasks/abc194_e
  // https://atcoder.jp/contests/abc194/submissions/20747756

  // えびちゃん
  // https://rsk0315.hatenablog.com/entry/2020/10/11/125049
}

// =================================================================================================== //

class UnionFind{
public:
  vector<int> p;		// 親
  vector<int> rank;	// サイズ・各集合の根のみ有効
  UnionFind(int n){
    p.resize(n, -1);
    rank.resize(n, 1);
  }
  int root(int x){
    if(p[x] == -1) return x;
    else return p[x] = root(p[x]); // 深さを 1 にしている
  }
  bool unite(int x, int y){
    x = root(x); y = root(y);
    if(x == y) return false;
    if(rank[x] > rank[y]) swap(x, y); // rankの小さいものを下につける
    rank[y] += rank[x];
    p[x] = y;
    return true;
  }
  // グループの数
  ll root_num() {
    ll num = 0;
    for(ll x : p) if (x < 0) num++;
    return num;
  }
  // グループごとに頂点をまとめる: O(N log N)
  map<int, vector<int>> groups(){
    map<int, vector<int>> ret;
    rep(i, p.size()) ret[root(i)].emplace_back(i);
    return ret;
  }
  //xが属すグループのサイズ
  int size(int x){ return rank[root(x)]; }
  bool same(int x, int y){ return (root(x) == root(y)); }
};

// Segment Tree
// セグメント木
// https://www.creativ.xyz/segment-tree-entrance-999/
// 使用関数の引数は全て1-index
// query() は半開区間
// ===================  問題ごとに設定 ====================
// !!使う前に init() を呼ぶ!!
const int N = 1 << 20;              // 葉の数、2の累乗数
const ll E = 0;                     // 演算での単位元
ll op(ll a, ll b) { return a + b; } // 使用する演算、可換
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

// Lazy Segment Tree
// 遅延評価セグメント木
// https://atcoder.github.io/ac-library/production/document_ja/lazysegtree.html
// チートシート
// https://betrue12.hateblo.jp/entry/2020/09/23/005940
// apply(l, r, f) が区間更新
// apply(p, f) が1点更新
// prod(l, r) が区間取得
// get(p) が 1点取得

// BIT
// Binary Indexed Tree
// https://scrapbox.io/pocala-kyopro/%E8%BB%A2%E5%80%92%E6%95%B0
// 1-index
struct BIT {
private:
  vector<int> bit;
  int N;

public:
  BIT(int size) {
    N = size;
    bit.resize(N + 1);
  }

  // 一点更新
  void add(int a, int w) {
    for (int x = a; x <= N; x += x & -x) bit[x] += w;
  }

  // 1~Nまでの和を求める。
  int sum(int a) {
    int ret = 0;
    for (int x = a; x > 0; x -= x & -x) ret += bit[x];
    return ret;
  }
};

// Mo's algorithm
// クエリ平方分割
// O( (N + Q)√N + Q log Q )
// 引数と返り値は 0-index
// https://ei1333.hateblo.jp/entry/2017/09/11/211011
// TLEしてるけど、こんな感じで使う https://atcoder.jp/contests/abc174/submissions/17716967
struct Mo {
  vector<int> left, right, order;
  vector<bool> v;
  int width, nl, nr, ptr, qi;
  // Mo(num_cnt, query_cnt)
  Mo(int n, int q) : width((int)sqrt(n)), nl(0), nr(0), ptr(0), v(n) {
    left.resize(q);
    right.resize(q);
    qi = 0;
  }
  void insert(int l, int r) { // 0-index, 半開区間
    left[qi] = l;
    right[qi] = r;
    qi++;
  }
  void build() { // sort
    order.resize(left.size());
    iota(ALL(order), 0);
    sort(ALL(order), [&](int a, int b) {
      if(left[a] / width != left[b] / width) return left[a] < left[b];
      return right[a] < right[b];
    });
  }
  int process() { // クエリを1つ処理してクエリのidを返す
    if(ptr == (int)order.size()) return (-1);
    const auto id = order[ptr];
    while(nl > left[id]) distribute(--nl);
    while(nr < right[id]) distribute(nr++);
    while(nl < left[id]) distribute(nl++);
    while(nr > right[id]) distribute(--nr);
    return (order[ptr++]);
  }
  inline void distribute(int idx) {
    v[idx].flip();
    if(v[idx]) add(idx);
    else del(idx);
  }
  // ===================  問題ごとに設定 ====================
  void add(int idx);
  void del(int idx);
  // =======================================================
};
// Mo's algorithm ここまで

// 行列クラス
// - 任意のサイズの行列同士の演算[+][-][x]
// - Matrix::E(int n) でn次単位行列
// - .val[][] で要素にアクセス
class Matrix {
protected:
  int size_y, size_x;

public:
  Matrix(int _y, int _x) {
    size_y = _y;
    size_x = _x;
    val = vector<vector<ll>>(_y, vector<ll>(_x, 0));
  }
  vector<vector<ll>> val;

  Matrix operator - () {
    for(int y = 0; y < size_y; ++y)
    for(int x = 0; x < size_x; ++x) {
      this->val[y][x] *= -1;
    }
  }
  Matrix operator + (Matrix right) const {
    auto left = *this;
    if (!same_size(&right)) {
      cerr << "invalid size" << endl;
      return E(1);
    }

    auto ret = Matrix(size_y, size_x);
    for(int y = 0; y < size_y; ++y)
    for(int x = 0; x < size_x; ++x) {
      ret.val[y][x] = left.val[y][x] + right.val[y][x];
    }
    return ret;
  }
  Matrix operator - (Matrix right) const {
    return (*this + -right);
  }
  void operator += (Matrix right) { *this = *this + right; }
  void operator -= (Matrix right) { *this = *this - right; }
  Matrix operator * (Matrix right) const {
    auto left = *this;
    if (left.x() != right.y()) {
      cerr << "invalid size" << endl;
      return E(1);
    }

    auto ret = Matrix(left.y(), right.x());
    for(int y = 0; y < (int)ret.val.size(); ++y)
    for(int x = 0; x < (int)ret.val[0].size(); ++x) {
      for(int i = 0; i < left.x(); ++i) {
        ret.val[y][x] += left.val[y][i] * right.val[i][x];
      }
    }
    return ret;
  }
  void operator *= (Matrix right) { *this = *this * right; }

  static Matrix E(int _size) {// ::演算子でアクセス
    auto ret = Matrix(_size, _size);
    for(int i = 0; i < _size; ++i) {
      ret.val[i][i] = 1;
    }
    return ret;
  }
  int x() const { return this->size_x; }
  int y() const { return this->size_y; }
  bool same_size(Matrix* other) const { return ((this->x() == other->x()) && (this->y() == other->y())); }
  void print() const {
    for(int y = 0; y < size_y; ++y) {
      for(int x = 0; x < size_x; ++x) {
        cout << val[y][x] << " ";
      }
      cout << endl;
    }
  }
};

// アフィン変換用の行列クラス
// - 拡大
// - 平行移動
// - 原点中心の回転
// - スキュー
// - x軸反転・y軸反転
class AffineMatrix : public Matrix {
public:
  AffineMatrix() : Matrix(3, 3){ val[2][2] = 1; }
  void operator = (Matrix other) {
    this->val = other.val;
    this->size_x = other.x();
    this->size_y = other.y();
  }
  void zoom(int _x, int _y) {
    Matrix mat = Matrix::E(3);
    mat.val[0][0] = _x;
    mat.val[1][1] = _y;
    *this = mat * (*this);
  }
  void move(int _x, int _y) {
    Matrix mat = Matrix::E(3);
    mat.val[0][2] = _x;
    mat.val[1][2] = _y;
    *this = mat * (*this);
  }
  void rotate(int _angle) { // 原点中心に反時計回り
    _angle %= 360;
    if (_angle == 90) {
      AffineMatrix mat;
      mat.val[0][1] = -1;
      mat.val[1][0] = 1;
      *this = mat * (*this);
    }
    else if (_angle == 180) {
      AffineMatrix mat;
      mat.val[0][0] = -1;
      mat.val[1][1] = -1;
      *this = mat * (*this);
    }
    else if (_angle == 270) {
      AffineMatrix mat;
      mat.val[0][1] = 1;
      mat.val[1][0] = -1;
      *this = mat * (*this);
    }
    else if (_angle == 360) {
      // do nothing
    }
    else {
      // { cos -sin   0}{ x }
      // { sin  cos   0}{ y }
      // {   0    0   1}{ 1 }
    }
  }
  /*
  void skew_x(int _angle) {
    // {   1  0  0}{ x }
    // { tan  1  0}{ y }
    // {   0  0  1}{ 1 }
  }
  void skew_y(int _angle) {
    // {  1  tan   0}{ x }
    // {  0    1   0}{ y }
    // {  0    0   1}{ 1 }
  }
  */
  void flip_x() { zoom(-1, 1); }
  void flip_y() { zoom(1, -1); }
};


void solve()
{
/*
  int n;
  cin >> n;

  bool y = n > 0;

  YN(y);
*/

  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n)
  {
    cin >> a[i];
  }
}

int main()
{
  solve();

  return 0;
}