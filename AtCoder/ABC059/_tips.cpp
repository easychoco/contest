// https://github.com/atcoder/live_library
// https:// qiita.com/kawa-Kotaro/items/782bc31b64e4ee13649a

// --std=c++14 -Wl,--stack,10485760 

#include <bits/stdc++.h>

#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()

using namespace std;
using ll = long long;
using P = pair<int, int>;

const double PI = 3.14159265358979;

// 最大公約数 : 3,4 ->  1
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

// 最小公倍数 : 3,4 -> 12
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

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

void tip_algorithm()
{
  auto vec = vector<int> { 0, 1, 2 };
  int x = 4, y = 5;

  for(auto &v : vec) {}	// 走査

  swap(x, y);				// 値を交換する
}

// 素因数分解
void tip_facotization()
{
  ll n;
  map<ll, ll> primes;
  int factor = 2;
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

// ワーシャルフロイド法・全点対最短経路 O(n^3)
void tip_warshall_floyd(int n) {
  int d[300][300];
  for (int k = 0; k < n; k++){			// 経由する頂点
    for (int i = 0; i < n; i++) {		// 始点
      for (int j = 0; j < n; j++) {	// 終点
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
}

// Dijkstra法
struct Edge{ ll cost, to; };
void dijkstra()
{
  ll n, u, v, w;
  cin >> n;
  vector< vector<Edge> > G(n, vector<Edge>());
  for(int i = 0; i < n; ++i)
  {
    cin >> u >> v >> w;
    u--; v--;
    G[u].emplace_back(Edge{w, v});
    G[v].emplace_back(Edge{w, u});
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

void tip_binary_search()
{
  auto f = [&](ll arg){ return arg; };
  ll x;
  ll le = 0, re = 1000000000LL;
  while(re - le > 1)
  {
    ll mid = (le + re) / 2;
    if ( x < f(x) ) re = mid;
    else le = mid;
  }
}

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
  //xが属すグループのサイズ
  int size(int x){ return rank[root(x)]; }
  bool same(int x, int y){ return (root(x) == root(y)); }
};

// Segment Tree
// https://www.creativ.xyz/segment-tree-entrance-999/
// 使用関数の引数は全て1-index
// ===================  問題ごとに設定 ====================
const int N = 1 << 20;              // 葉の数、2の累乗数
const ll E = 0;                     // 演算での単位元
ll op(ll a, ll b) { return a + b; } // 使用する演算、非可換
// !!使う前に init() を呼ぶ!!
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
    node[i] = op(node[i * 2 + 1], node[i * 2 + 2]); // 左右の子の min を計算しなおす
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
  int x;
  cin >> x;
  cout << (x ? "Yes" : "No");

  ll n;
  cin >> n;
  vector<ll> a(n);
  for(int i = 0; i < n; ++i)
  {
    cin >> a[i];
  }
}

int main()
{
  solve();

  return 0;
}