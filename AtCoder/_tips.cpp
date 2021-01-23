// https://github.com/atcoder/live_library
// https:// qiita.com/kawa-Kotaro/items/782bc31b64e4ee13649a

// --std=c++14 -Wl,--stack,10485760 

#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i=a;i<(ll)n;++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define Show(val) cout<<(val)<<" "
#define Showln(val) cout<<(val)<<endl

using namespace std;
using ll = long long;
using P = pair<ll, ll>;
// using P = pair<int, int>;
void YN(bool a) { cout << (a ? "Yes" : "No"); }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

// 最大公約数 : 3,4 ->  1
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

// 最小公倍数 : 3,4 -> 12
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

// https://www.youtube.com/watch?v=hY2FicqnAcc
// 拡張GCD : O(log b)
// a と b の gcd を求める
// ax + by = gcd となるx, yを求める
// b を mod にすると、mod が素数でないときも逆元を求められる
tuple<ll, ll, ll> extgcd(ll a, ll b)
{
  if (b == 0) return make_tuple(a, 1LL, 0LL);
  ll g, x, y;
  tie(g, x, y) = extgcd(b, a % b);
  return make_tuple(g, y, x - (a / b) * y);
}

// 素数判定
bool isPrime(int a) {
    if (a == 1) return false;
    for (int i = 2; i * i <= a; i++) {
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

// =================================================================================================== //

// 素因数分解
void tip_facotization()
{
  ll n;
  map<ll, ll> primes;
  ll factor = 2;
  while(factor * factor <= n)
  {
    if (n % factor == 0)
    {
      primes[factor]++;
      n /= factor;
    }
    else ++factor;
  }
  primes[n]++;
}

// 二分探索
// めぐる式
void tip_binary_search()
{
  auto f = [&](ll arg)
  {
    return arg;
  };
  ll ac = 0, wa = 1000000000LL;
  while(wa - ac > 1)
  {
    ll wj = (ac + wa) / 2;
    if ( f(wj) ) ac = wj;
    else wa = wj;
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
  const ll INF = 100100100100;
  const int N = 300;
  ll d[N][N];
  rep(i, N) rep(j, N) d[i][j] = INF;
  rep(i, N) d[i][i] = 0;

  rep (k, n){       // 経由する頂点
    rep (i, n) {    // 始点
      rep (j, n) {  // 終点
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
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
struct Edge{ ll cost, to; };
void dijkstra()
{
  // 重みに負値があるときはベルマンフォード法を使う

  // w=1(固定長)の時はpriority_queueをqueueにするとO(NlogN)がO(logN)になる
  // 大抵は不要だけどO(NlogN)では厳しいときに
  // 下のtip_graph_bfsも検討
  ll n, u, v, w;
  cin >> n;
  vector< vector<Edge> > G(n, vector<Edge>());
  for(int i = 0; i < n; ++i)
  {
    cin >> u >> v >> w;
    u--; v--;
    G[u].emplace_back(Edge{w, v});
    G[v].emplace_back(Edge{w, u}); // 無向グラフの場合
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
    ll node = p.second;
    if (d[node] < p.first) continue;
    for (const auto& edge : G[node])
    {
      if (d[edge.to] > d[node] + edge.cost)
      {
        d[edge.to] = d[node] + edge.cost;
        que.push(P(d[edge.to], edge.to));
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
        que.push(to);
    }
  }
}

// トポロジカルソート
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
    for(const auto& v : edge[now])
    {
      deg[v]--;
      if (deg[v] == 0) que.push(v);
    }
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
  repi(i, 1, n) dp[1<<i][i] = dist[0][i];
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

// =================================================================================================== //

void tip_string()
{
  string s, t;

  s = s + t;			// 連結
  s == t;				// 比較
  s.length();			// 長さ
  s[3];				// 3番目の文字を参照
  s.substr(3, 5);		// 3番目以降5文字を抽出して得られる文字列
  s.find(t); 			// sの中に文字列tがあればその先頭のアドレスを返す．なければs.nposを返却
  s.replace(3, 5, t);	// 3番目以降5文字を文字列tで置換する．tを空文字列にすれば削除の動作
  s.insert(3, t);		// 3番目の文字の前に文字列tを挿入	
}

void tip_vector()
{
  vector<int> vec(5);

  vec.size();			// vecの大きさ
  vec[3];				// i番目の要素にアクセス
  vec.front();		// 先頭を参照
  vec.back();			// 末尾を参照
  vec.push_back(2);	// 末尾に要素を追加
  vec.pop_back();		// 末尾の要素を削除


  reverse(vec.begin(),vec.end());					//要素の順番を逆にする

  sort(vec.begin(), vec.end());					// 昇順ソート
  sort(vec.begin(), vec.end(), greater<int>());	// 降順ソート
  sort(vec.begin(), vec.end(),  [](auto const& l, auto const& r){
    return abs(l) < abs(r);
  });// 自作ソート・昇順

  int x = 2;	// 探索対象
  binary_search(vec.begin(), vec.end(), x);		// trueかfalseを返す
  lower_bound(vec.begin(), vec.end(), x);			// x以上の値が初めて現れる位置のイテレータを返す
  upper_bound(vec.begin(), vec.end(), x);			// xより大きい値が初めて現れる位置のイテレータを返す
  equal_range(vec.begin(), vec.end(), x);			// 上記2カ所のイテレータのペアを返す

}

void tip_list()
{
  list<int> li;
  list<int>::iterator p, q;
  list<int>::reverse_iterator r;

  li.push_front(3);	// 先頭に挿入
  li.front();			// 先頭の要素を参照
  li.pop_front();		// 先頭の要素を削除
  li.push_back(3);	// 末尾に挿入
  li.back();			// 末尾の要素を参照
  li.pop_back();		// 末尾の要素を削除
  li.begin();			// 最初の要素を指すイテレーター
  li.end();			// 末尾の次の要素を指すイテレーター
  li.rbegin();		// 逆順にした時の最初の要素を指すイテレーター
  li.rend();			// 逆順にした時の末尾の次の要素を指すイテレーター
  li.insert(p, 3);	// pのさす要素の直前に3を挿入
  li.erase(p);		// pの指す要素を削除
  li.erase(p, q);		// pの指す要素からqの指す要素まで削除
  li.clear();			// リストの全要素を削除
  *p;					// イテレーターの指す要素
  p++;				// 走査方向に向かって次の要素を指すイテレーター
  p--;				// 走査方向に向かって前の要素を指すイテレーター
  for (p=li.begin(); p!=li.end(); p++) { *p = 0; }	// 前から走査
  for (r=li.rbegin(); r!=li.rend(); r++) { *r = 9; }	// 後ろから走査	
}

void tip_deque() 		// stack と queue の性質を持つ
{
  deque<int> d;

  d.push_front(2);	// 先頭に挿入
  d.front();			// 先頭の要素を参照
  d.pop_front();		// 先頭の要素を削除
  d.push_back(2);		// 末尾に挿入
  d.back();			// 末尾の要素を参照
  d.pop_back();		// 末尾の要素を削除
}

struct My{
  ll sum, i, j, k;
  bool operator < (const My& other) const
  { // 自作の構造体・最大値から
    return sum < other.sum;
  }
};
void tip_priority_queue()
{
  priority_queue<int> que;	// 最大値から出てくるヒープ

  priority_queue< int, vector<int>, greater<int> > min_que;	// 最小値から出てくるヒープ 

  que.push(2);		// 要素の追加
  que.top();			// 先頭をみる
  que.pop();			// 先頭を削除
}

void tip_map()
{
  map<string, int> m;	// キーがstring型，要素がint型
  map<string, int>::iterator p;

  m["apple"] = 10;	// 要素にアクセス
  p = m.find("apple");// 要素へのイテレーターを返す．なければm.end()を返却
  p->first;			// firstがキー
  p->second;			// secondが値
  m.erase(p);			// イテレーターの指す要素を削除
}

void tip_set()
{
  set<int> s;
  multiset<int> ms;	// 重複を許す場合

  s.insert(2);		// 要素の追加
  s.erase(2);			// 要素の削除
  s.find(2);			// 発見したらその要素へのイテレータを返す,なければend()を返す
  s.count(2);			// 要素の数を返す
  s.lower_bound(2); // 二分探索 : lower_bound(ALL(s)) は O(N) かかる
  s.upper_bound(2); // 二分探索 : upper_bound(ALL(s)) は O(N) かかる
  s.empty();			// 空ならtrue
  s.size();			// 要素数を返却
  s.clear();			// 空にする
}

void tip_unordered_set()
{
  unordered_set<int> s;
  unordered_multiset<int> ms;	// 重複を許す場合

  s.insert(2);		// 要素の追加
  s.erase(2);			// 要素の削除
  s.find(2);			// 発見したらその要素へのイテレータを返す
  s.count(2);			// 要素の数を返す
  s.empty();			// 空ならtrue
  s.size();			// 要素数を返却
  s.clear();			// 空にする
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
  void unite(int x, int y){
    x = root(x); y = root(y);
    if(x == y)return;
    if(rank[x] > rank[y]) swap(x, y); // rankの小さいものを下につける
    rank[y] += rank[x];
    p[x] = y;
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
    for(int y = 0; y < ret.val.size(); ++y)
    for(int x = 0; x < ret.val[0].size(); ++x) {
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
  void flip_x() { zoom(-1, 1); }
  void flip_y() { zoom(1, -1); }
};


void solve()
{
  int x;
  cin >> x;

  bool y = x > 0;

  YN(y);


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