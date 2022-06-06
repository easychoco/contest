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
using namespace chrono;
using vb = vector<bool>;
using vvb = vector<vb>;
using vs = vector<string>;
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

class UnionFind{
public:
  vector<ll> p;		// 親
  vector<ll> rank;	// サイズ・各集合の根のみ有効
  ll root_num; // 連結成分の数
  UnionFind(ll n) : root_num(n) {
    p.resize(n, -1);
    rank.resize(n, 1);
  }
  ll root(ll x){
    if(p[x] == -1) return x;
    else return p[x] = root(p[x]); // 深さを 1 にしている
  }
  bool unite(ll x, ll y){
    x = root(x); y = root(y);
    if(x == y) { rank[x] = rank[y] = 0; return false; } // ループしているものは対象外
    if(rank[x] > rank[y]) swap(x, y); // rankの小さいものを下につける
    rank[y] += rank[x];
    p[x] = y;
    root_num--;
    return true;
  }
  // グループごとに頂点をまとめる: O(N log N)
  map<ll, vector<ll>> groups(){
    map<ll, vector<ll>> ret;
    rep(i, p.size()) ret[root(i)].emplace_back(i);
    return ret;
  }
  //xが属すグループのサイズ
  ll size(ll x){ return rank[root(x)]; }
  bool same(ll x, ll y){ return (root(x) == root(y)); }
  ll max_size() { return *max_element(ALL(rank)); }
};

// 0以上 UINT_MAX(0xffffffff)以下の整数をとる乱数 xorshift
// https://ja.wikipedia.org/wiki/Xorshift
static uint32_t randXor()
{
  static uint32_t x = 123456789;
  static uint32_t y = 362436069;
  static uint32_t z = 521288629;
  static uint32_t w = 88675123;
  uint32_t t;
  t = x ^ (x << 11);
  x = y; y = z; z = w;
  return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}

// 0以上1未満の小数をとる乱数
static double rand01()
{
    return (randXor() + 0.5) * (1.0 / UINT_MAX);
}

const ll L = 0b0001;
const ll U = 0b0010;
const ll R = 0b0100;
const ll D = 0b1000;

class Tile {
public:
  Tile() {};
  Tile(ll _mask):
    mask(_mask)
  {};

  bool isLeft() {
    return (mask & L) > 0;
  }
  bool isUp() {
    return (mask & U) > 0;
  }
  bool isRight() {
    return (mask & R) > 0;
  }
  bool isDown() {
    return (mask & D) > 0;
  }

private:
  ll mask;
};

// 地獄の if文
ll toMask(char c)
{
  if (c == '0') return 0;
  if (c == '1') return 1;
  if (c == '2') return 2;
  if (c == '3') return 3;
  if (c == '4') return 4;
  if (c == '5') return 5;
  if (c == '6') return 6;
  if (c == '7') return 7;
  if (c == '8') return 8;
  if (c == '9') return 9;
  if (c == 'a') return 10;
  if (c == 'b') return 11;
  if (c == 'c') return 12;
  if (c == 'd') return 13;
  if (c == 'e') return 14;
  if (c == 'f') return 15;
  return -10;
}

// ===========================
//          variables
// ===========================

ll n, t;

ll zero_x, zero_y;
vector<vector<Tile>> mp;

ll initial_zero_x, initial_zero_y;
vector<vector<Tile>> initial_mp;

void input()
{
  cin >> n >> t;
  mp.resize(n); initial_mp.resize(n);
  rep(i, n) { mp[i].resize(n); initial_mp[i].resize(n); }
  rep(y, n)
  {
    string s;
    cin >> s;
    rep(x, n)
    {
      initial_mp[y][x] = Tile(toMask(s[x]));
      if (s[x] == '0')
      {
        initial_zero_y = y;
        initial_zero_x = x;
      }
    }
  }
}

void initialize()
{
  zero_x = initial_zero_x;
  zero_y = initial_zero_y;
  mp = initial_mp;
}

// 連結成分ごとに UF を構築する
UnionFind buildUF()
{
  UnionFind uf(n * n);
  rep(y, n)
  rep(x, n - 1)
  {
    if (mp[y][x].isRight() && mp[y][x + 1].isLeft()) uf.unite(y * n + x, y * n + x + 1);
  }

  rep(y, n - 1)
  rep(x, n)
  {
    if (mp[y][x].isDown() && mp[y + 1][x].isUp()) uf.unite(y * n + x, (y + 1) * n + x);
  }

  return uf;
}

ll calcScoreWithUF(UnionFind uf)
{
  ll sz = uf.max_size();
  return sz;
  // ll point = 500000LL * sz / (n * n - 1);
  // return point;
}

ll calcScore()
{
  return calcScoreWithUF(buildUF());
}

// 空欄と左側を入れ替える
bool trySwapLeft()
{
  if (zero_x == 0) return false;

  swap(mp[zero_y][zero_x], mp[zero_y][zero_x - 1]);
  zero_x--;
  return true;
}

// 空欄と上側を入れ替える
bool trySwapUp()
{
  if (zero_y == 0) return false;

  swap(mp[zero_y][zero_x], mp[zero_y - 1][zero_x]);
  zero_y--;
  return true;
}

// 空欄と右側を入れ替える
bool trySwapRight()
{
  if (zero_x == n - 1) return false;

  swap(mp[zero_y][zero_x], mp[zero_y][zero_x + 1]);
  zero_x++;
  return true;
}

// 空欄と下側を入れ替える
bool trySwapDown()
{
  if (zero_y == n - 1) return false;

  swap(mp[zero_y][zero_x], mp[zero_y + 1][zero_x]);
  zero_y++;
  return true;
}

// route の通りに動いてみる
// 実際に動いたルートを返す
string tryMove(string route, bool reverse_and_back = false)
{
  string move_hist = "";
  auto success = [&](char c)
  {
    move_hist += c;
  };

  if (reverse_and_back)
  {
    rrep(i, route.length() - 1)
    {
      char c = route[i];
      if (c == 'L')
      {
        if (trySwapRight()) success(c);
      }
      else if (c == 'U')
      {
        if (trySwapDown()) success(c);
      }
      else if (c == 'R')
      {
        if (trySwapLeft()) success(c);
      }
      else if (c == 'D')
      {
        if (trySwapUp()) success(c);
      }
    }
  }
  else
  {
    rep(i, route.length())
    {
      char c = route[i];
      if (c == 'L')
      {
        if (trySwapLeft()) success(c);
      }
      else if (c == 'U')
      {
        if (trySwapUp()) success(c);
      }
      else if (c == 'R')
      {
        if (trySwapRight()) success(c);
      }
      else if (c == 'D')
      {
        if (trySwapDown()) success(c);
      }
    }
  }
  return move_hist;
}


// 動いてみたときのルートとスコアを返す
pair<string, ll> localSearch(string route)
{
  string actual_route = tryMove(route);
  ll score = 0;
  if (actual_route.length())
  {
    score = calcScore();
    tryMove(actual_route, true);
  }
  return make_pair(actual_route, score);
}

vs generateSearchRoute(ll depth)
{
  vs ret;
  queue<string> que;
  que.push("L");
  que.push("U");
  que.push("R");
  que.push("D");
  while (que.size())
  {
    string now = que.front();
    que.pop();
    ret.pb(now);
    if ((ll)now.length() < depth)
    {
      if (now.back() != 'L') que.push(now + 'U');
      if (now.back() != 'U') que.push(now + 'L');
      if (now.back() != 'R') que.push(now + 'R');
      if (now.back() != 'D') que.push(now + 'D');
    }
  }
  return ret;
}

// =======================================
//                  1回分
// =======================================
pair<string, ll> step()
{
  static vs candidates = generateSearchRoute(1);
  return localSearch(candidates[randXor() % candidates.size()]);
}

bool apply(
  double current_score,
  double next_score,
  const double start_temp,
  const double end_temp,
  double now_time,
  const double max_time
){
  // 今の温度
  double temp = max(0.0000000001, end_temp + (start_temp - end_temp) * (max_time - now_time) / max_time);
  double prob = exp((next_score - current_score) / temp);
  return rand01() < prob;
}

// =======================================
//                  main
// =======================================

void solve()
{
  auto startClock = system_clock::now();

  input();
  initialize();
  string ans = "";
  ll score = 0;

  const static double END_TIME = 2.80; // 終了時間（秒）
  double time = 0.0; // 経過時間（秒）

  const double start_temp = n * n;
  const double end_temp = 0.0;

  ll max_score = 0;
  string max_ans = "";

  do {
    auto [a, s] = step();
    if (apply(
      score,
      s,
      start_temp,
      end_temp,
      time,
      END_TIME
    ))
    {
      if ((ll)(ans + a).length() > t)
      {
        if (chmax(max_score, score)) max_ans = ans;
        ans = "";
        initialize();
        continue;
      }

      score = s;
      ans += tryMove(a);
    }
    time = (duration_cast<microseconds>(system_clock::now() - startClock).count() * 1e-6);
  } while (time < END_TIME);

  print(max_ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}
