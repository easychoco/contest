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
  ll point = 500000LL * sz / (n * n - 1);
  return point;
}

ll calcScore()
{
  return calcScoreWithUF(buildUF());
}

ll calcSizeOf(ll target)
{
  UnionFind uf = buildUF();
  // auto check_outer_edge = [&](ll x, ll y)
  // {
  //   ll now = y * n + x;
  //   ll ret = 0;
  //   // L
  //   if (x > 0 && mp[y][x].isLeft() && !uf.same(now, now - 1)) ret++;
  //   // U
  //   if (y > 0 && mp[y][x].isUp() && !uf.same(now, now - n)) ret++;
  //   // R
  //   if (x < n - 1 && mp[y][x].isRight() && !uf.same(now, now + 1)) ret++;
  //   // D
  //   if (y < n - 1 && mp[y][x].isDown() && !uf.same(now, now + n)) ret++;
  //   return ret;
  // };

  // ll outer_edge_count = 0;
  // rep(y, n) {
  //   rep(x, y) {
  //     if (uf.same(target, y * n + x)) outer_edge_count += check_outer_edge(x, y);
  //   }
  // }

  // return uf.size(target) + outer_edge_count / 5;
  return uf.size(target);
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

string tryMoveTo(ll to_x, ll to_y)
{
  string try_move_route = "";

  ll dx = to_x - zero_x;
  if (dx > 0) try_move_route += string(dx, 'R');
  else try_move_route += string(-dx, 'L');

  ll dy = to_y - zero_y;
  if (dy > 0) try_move_route += string(dy, 'D');
  else try_move_route += string(-dy, 'U');

  return tryMove(try_move_route);
}

// zero_x, zero_y から見て　groupIndices 上の最寄りの点を返す
pair<ll, ll> findNearestPosition(vl groupIndices)
{
  ll to_x = INF;
  ll to_y = INF;

  for (auto groupIndex : groupIndices)
  {
    ll x = groupIndex % n;
    ll y = groupIndex / n;
    if (abs(zero_x - x) + abs(zero_y - y) < abs(zero_x - to_x) + abs(zero_y - to_y))
    {
      to_x = x;
      to_y = y;
    }
  }
  return make_pair(to_x, to_y);
}

// 動いてみたときのルートとサイズを返す
pair<string, ll> localSearch(string route, ll target_group_root)
{
  string actual_route = tryMove(route);
  ll size = 0;
  if (actual_route.length())
  {
    size = calcSizeOf(target_group_root);
    tryMove(actual_route, true);
  }
  return make_pair(actual_route, size);
}

string moveNextOrbitalPosition(ll target_group_root, char last_move, bool isClockwise = true)
{
  UnionFind uf = buildUF();
  vvl neighbor_map {
    { -10, -10, -10, },
    { -10, 0, -10, },
    { -10, -10, -10, },
  };

  /**
   * n = 6
   * [  0,  1,  2,  3,  4,  5 ]
   * [  6,  7,  8,  9, 10, 11 ]
   * [ 12, 13, 14, 15, 16, 17 ]
   * [ 18, 19, 20, 21, 22, 23 ]
   * [ 24, 25, 26, 27, 28, 29 ]
   * [ 30, 31, 32, 33, 34, 35 ]
   */

  auto paddingAt = [&](ll y, ll x)
  {
    bool ok_vertical = true;
    bool ok_horizontal = true;
    ll pos = zero_y * n + zero_x;

    // neighbor_map[y][x] が mp の内側かどうかを判定する
    if (y == 0) { ok_vertical = (pos / n > 0); pos -= n; }
    else if (y == 1);
    else if (y == 2) { ok_vertical = (pos / n < n - 1); pos += n; }
    else return;

    if (x == 0) { ok_horizontal = (pos % n > 0); pos--; }
    else if (x == 1);
    else if (x == 2) { ok_horizontal = (pos % n < n - 1); pos++; }
    else return;

    if (ok_vertical && ok_horizontal)
    {
      neighbor_map[y][x] = uf.same(target_group_root, pos);
    }
  };

  paddingAt(0, 0); paddingAt(0, 1); paddingAt(0, 2);
  paddingAt(1, 0);                  paddingAt(1, 2);
  paddingAt(2, 0); paddingAt(2, 1); paddingAt(2, 2);

  vs candidate;
  if (neighbor_map[0][1] == 0)
  {
    if (last_move != 'D') candidate.pb("U");
    if (isClockwise && neighbor_map[0][2] == 0) candidate.pb("UR");
    if (!isClockwise && neighbor_map[0][0] == 0) candidate.pb("UL");
  }

  if (neighbor_map[1][2] == 0)
  {
    if (last_move != 'L') candidate.pb("R");
    if (isClockwise && neighbor_map[2][2] == 0) candidate.pb("RD");
    if (!isClockwise && neighbor_map[0][2] == 0) candidate.pb("RU");
  }

  if (neighbor_map[2][1] == 0)
  {
    if (last_move != 'U') candidate.pb("D");
    if (isClockwise && neighbor_map[2][0] == 0) candidate.pb("DL");
    if (!isClockwise && neighbor_map[2][2] == 0) candidate.pb("DR");
  }

  if (neighbor_map[1][0] == 0)
  {
    if (last_move != 'R') candidate.pb("L");
    if (isClockwise && neighbor_map[0][0] == 0) candidate.pb("LU");
    if (!isClockwise && neighbor_map[0][2] == 0) candidate.pb("LD");
  }

  if (candidate.size() == 0)
  {
    return "";
    // if (last_move != 'D') candidate.pb("UUU");
    // if (last_move != 'L') candidate.pb("RRR");
    // if (last_move != 'U') candidate.pb("DDD");
    // if (last_move != 'R') candidate.pb("LLL");
  }
  ll idx = randXor() % candidate.size();
  return tryMove(candidate[idx]);
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

pair<string, ll> step(pair<ll, vl> initial_group)
{
  // この点をふくむ集合を軌道周回する
  ll target_group_root = initial_group.first;
  string max_score_route = "";
  ll max_score = 0;

  bool clockwise = true;
  ll not_update_count = 0;

  auto [to_x, to_y] = findNearestPosition(initial_group.second);
  string now_route = tryMoveTo(to_x, to_y);
  ll now_group_size = calcSizeOf(target_group_root);

  while((ll)now_route.length() < t)
  {
    string before_route = now_route;
    string init_route = moveNextOrbitalPosition(target_group_root, now_route.back(), clockwise);
    string next_route = "";

    // localSearch に使うルートを列挙する
    // vs search_route { 
    //   // 1回移動
    //   "L", "U", "R", "D",
    //   // 2回移動
    //   "LD", "LL", "LU",
    //   "UL", "UU", "UR",
    //   "RU", "RR", "RD",
    //   "DR", "DD", "DL",
    //   // 3回移動
    //   "LDD", "LDL", "LLD", "LLL", "LLU", "LUL", "LUU",
    //   "ULL", "ULU", "UUL", "UUU", "UUR", "URU", "URR",
    //   "RUU", "RUR", "RRU", "RRR", "RRD", "RDR", "RDD",
    //   "DRR", "DRD", "DDR", "DDD", "DDL", "DLD", "DLL",
    //   "LDR", "LUR", "ULD", "URD", "RUL", "RDL", "DRU", "DLU",
    // };

    for (auto r : generateSearchRoute(4))
    {
      auto [route, sz] = localSearch(r, target_group_root);
      if (chmax(now_group_size, sz)) next_route = route; 
    }

    // 焼きなましみたいなことをしてみる
    if ((ll)next_route.length() > 0) not_update_count = 0;
    else
    {
      // tryMove(init_route, true);
      // init_route = "";

      not_update_count++;
      if ((ll)now_route.length() < t / 3 && randXor() % t < not_update_count)
      {
        char unit[4] = { 'L', 'U', 'R', 'D' };
        ll move_dist = 1 + (randXor() % n) / 2;
        // vs candidate;
        // if (now_route.back() != 'D') candidate.pb(string(move_dist, 'U'));
        // if (now_route.back() != 'L') candidate.pb(string(move_dist, 'R'));
        // if (now_route.back() != 'U') candidate.pb(string(move_dist, 'D'));
        // if (now_route.back() != 'R') candidate.pb(string(move_dist, 'L'));
        next_route = string(move_dist, unit[randXor() % 4]);
        not_update_count = 0;
        // clockwise = !clockwise;
      }
    }

    // update map, route, score
    if ((ll)(now_route + init_route + next_route).length() <= t)
    {
      now_route += init_route + tryMove(next_route);
      now_group_size = calcSizeOf(target_group_root);
    }
    else tryMove(init_route, true);

    if (chmax(max_score, calcScore())) max_score_route = now_route;

    // 変わってないならバイバイ
    if (now_route == before_route) break;
  }
  return make_pair(max_score_route, max_score);
}

// =======================================
//                  main
// =======================================

void solve()
{
  auto startClock = system_clock::now();

  input();
  string ans = "";
  ll score = 0;

  const static double END_TIME = 2.80; // 終了時間（秒）
  double time = 0.0; // 経過時間（秒）

  UnionFind uf = buildUF();
  do {
    for (auto g : uf.groups())
    {
      initialize();
      auto [a, s] = step(g);
      if (chmax(score, s)) ans = a;
      time = (duration_cast<microseconds>(system_clock::now() - startClock).count() * 1e-6);
      if (time > END_TIME) break;
    }
  } while (time < END_TIME);

  print(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}
