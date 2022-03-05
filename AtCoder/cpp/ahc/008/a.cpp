#include <bits/stdc++.h>
#include <atcoder/all>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
// #define endl "\n"
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
void debug_impl() { cerr << endl; }
template <class Head, class... Tail>
void debug_impl(Head&& head, Tail&&... tail){ cerr << head << " "; debug_impl(std::forward<Tail>(tail)...); }
template <class... Head>
void debug(Head&&... head) { cerr << "# "; debug_impl(std::forward<Head>(head)...); }

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

int mp[30][30][4] = {};

const int NON   = 0;
const int BLOCK = 1;
const int MAN   = 2;
const int PET   = 3;

// ------------- Obj -------------
class Obj {
public:
  Obj(){};
  Obj(ll _x, ll _y):
    x(_x - 1),
    y(_y - 1)
  {};

  ll x;
  ll y;

  ll dist(Obj& _other) const
  {
    return abs(this->x - _other.x) + abs(this->y - _other.y);
  }
};


// ------------- Pet -------------
class Pet: public Obj {
public:
  Pet(): Obj(){};
  Pet(ll _x, ll _y, ll _sp):
    Obj(_x, _y),
    sp(_sp)
  {
    mp[x][y][PET]++;
  };

  ll sp;

  void mv(string _in)
  {
    for (auto c: _in)
    {
      ll nx = x;
      ll ny = y;
      if (c == 'U') nx--;
      if (c == 'D') nx++;
      if (c == 'L') ny--;
      if (c == 'R') ny++;      

      if (nx < 0 || 30 <= nx) continue;
      if (ny < 0 || 30 <= ny) continue;
      if (mp[nx][ny][BLOCK] > 0) continue;

      mp[x][y][PET]--;
      mp[nx][ny][PET]++;
      x = nx;
      y = ny;
    }
  }
};


// ------------- Man -------------
vp remove_list;

class Man: public Obj {
public:
  ll progress;
  string task;
  vp check_mp;

  Man(): Obj(), start_x(0), start_y(0){};
  Man(ll _x, ll _y, ll _count):
    Obj(_x, _y),
    start_x(x),
    start_y(y)
  {
    string risou[8];
    if (this->x > 15 && this->y > 15)
    {
      rep(i, 8) risou[i] = risou_of_rd[i];
    }
    else if (this->x > 15 && this->y <= 15)
    {
      rep(i, 8) risou[i] = risou_of_ld[i];
    }
    else if (this->x <= 15 && this->y > 15)
    {
      rep(i, 8) risou[i] = risou_of_ru[i];
    }
    else if (this->x <= 15 && this->y <= 15)
    {
      rep(i, 8) risou[i] = risou_of_lu[i];
    }

    {
      this->task += risou[0];
      rep(i, _count) this->task += risou[1];
      this->task += risou[2];
      rep(i, _count) this->task += risou[3];
      this->task += "*"; // half
      this->task += risou[4];
      rep(i, _count) this->task += risou[5];
      this->task += risou[6];
      rep(i, _count) this->task += risou[7];
    }

    this->progress = 0;
    mp[x][y][MAN]++;
  };

  // moveTo(ll x, ll y) { bfs(...); } とか
  // moveRight(bool make_up, bool make_down) とか作りたかったな...
  char now() const
  {
    return task[progress];
  }

  bool isHalf() const
  {
    return (now() == '*');
  }

  bool isMake() const
  {
    return 'a' <= now() && now() <= 'z';
  }

  bool isMove() const
  {
    return 'A' <= now() && now() <= 'Z';
  }

  bool isFinish() const
  {
    return this->progress >= (ll)this->task.length();
  }

  void reserve(string act)
  {
    // debug("reserve", this->progress, "from:", this->task);
    this->task.insert(this->progress, act);
    // debug(this->progress, " to :", this->task);
  }

  void replaceTask(string act)
  {
    this->task = act;
    this->progress = 0;
  }

  void slave(const Man _other)
  {
    this->task = _other.task;
    this->progress = _other.progress;
  }

  void validateRange()
  {
    ll fromx = min(start_x, x);
    ll tox   = max(start_x, x);
    ll fromy = min(start_y, y);
    ll toy   = max(start_y, y);

    repie(rx, fromx, tox)
    repie(ry, fromy, toy)
    {
      this->check_mp.pb(P(rx, ry));
    }

    this->progress++;
  }

  char move()
  {
    ll nx = x;
    ll ny = y;

    char c = this->now();
    this->progress++;
    if (c == 'U') nx--;
    if (c == 'D') nx++;
    if (c == 'L') ny--;
    if (c == 'R') ny++;

    if (nx < 0 || 30 <= nx) return '.';
    if (ny < 0 || 30 <= ny) return '.';
    if (mp[nx][ny][BLOCK] > 0) return '.';

    mp[nx][ny][MAN]++;
    remove_list.pb(P(x, y));

    this->x = nx;
    this->y = ny;
    return c;
  }

  char make(bool force = false)
  {
    // block をつくるとき
    ll nx = x;
    ll ny = y;
    const char c = now();
    if (c == 'u') nx--;
    if (c == 'd') nx++;
    if (c == 'l') ny--;
    if (c == 'r') ny++;

    bool ok = true;

    if (nx < 0 || 30 <= nx || ny < 0 || 30 <= ny)
    {
      this->progress++;
      return '.';
    }

    ok &= (mp[nx][ny][MAN] == 0);
    ok &= (mp[nx][ny][PET] == 0);
    ok &= ((nx ==  0) || (mp[nx - 1][ny][PET] == 0));
    ok &= ((nx == 29) || (mp[nx + 1][ny][PET] == 0));
    ok &= ((ny ==  0) || (mp[nx][ny - 1][PET] == 0));
    ok &= ((ny == 29) || (mp[nx][ny + 1][PET] == 0));

    // if (!(mp[nx][ny][MAN] == 0)) debug("out", 0, nx, ny, mp[nx][ny][MAN]);
    // if (!(mp[nx][ny][PET] == 0)) debug("out", 1, nx, ny, mp[nx][ny][PET]);
    // if (!(nx ==  0 || mp[nx - 1][ny][PET] == 0)) debug("out", 2, nx, ny, mp[nx - 1][ny][PET]);
    // if (!(nx == 29 || mp[nx + 1][ny][PET] == 0)) debug("out", 3, nx, ny, mp[nx + 1][ny][PET]);
    // if (!(ny ==  0 || mp[nx][ny - 1][PET] == 0)) debug("out", 4, nx, ny, mp[nx][ny - 1][PET]);
    // if (!(ny == 29 || mp[nx][ny + 1][PET] == 0)) debug("out", 5, nx, ny, mp[nx][ny + 1][PET]);

    if (!this->check_mp.empty() && !force)
    {
      for (auto& [rx, ry] : this->check_mp)
      {
        ok &= (mp[rx][ry][PET] == 0);
      }
    }


    if (!ok) return '.';

    mp[nx][ny][BLOCK]++;
    this->progress++;
    return c;
  }

private:
  ll start_x;
  ll start_y;
  queue<char> reserved;

  string risou_of_rd[8] { "d", "Ld", "l", "Ul", "u", "Ru", "r", "Dr" }; // "dLdLdlUlUluRuRurDrDr";
  string risou_of_ru[8] { "u", "Lu", "l", "Dl", "d", "Rd", "r", "Ur" }; // "uLuLulDlDldRdRdrUrUr";
  string risou_of_ld[8] { "d", "Rd", "r", "Ur", "u", "Lu", "l", "Dl" }; // "dRdRdrUrUruLuLulDlDl";
  string risou_of_lu[8] { "u", "Ru", "r", "Dr", "d", "Ld", "l", "Ul" }; // "uRuRurDrDrdLdLdlUlUl";
};


// ------------------------------------ ここからmain ------------------------------------

// g++ --std=gnu++17 -I ~/pg/ac-library -Wall -O2 ../a.cpp
void solve()
{
  ll n;
  cin >> n;
  
  vector<Pet> pet(n);
  
  rep(i, n)
  {
    ll x, y, t;
    cin >> x >> y >> t;
    pet[i] = Pet(x, y, t);
  }

  ll m;
  cin >> m;
  vector<Man> man(m);
  rep(i, m)
  {
    ll x, y;
    cin >> x >> y;
    man[i] = Man(x, y, 7);
  }

  rep (turn, 300)
  {
    debug("now is ", turn);
    string out = string(m, '.');

    // ターンのはじめにやること
    // 位置が近い人は統合しましょ
    rep(you, m)
    rep(me, you)
    {
      ll dist = man[me].dist(man[you]);
      if (dist == 0)
      {
        if (man[me].progress < man[you].progress) man[me].slave(man[you]);
        else man[you].slave(man[me]);
      }

      if (dist == 1)
      {
        string res = "";

        // 進んでいる方 にあわせる
        if (man[me].progress < man[you].progress)
        {
          // me を you のいるマスに移す
          if (man[me].x < man[you].x) res = "D";
          if (man[you].x < man[me].x) res = "U";
          if (man[me].y < man[you].y) res = "R";
          if (man[you].y < man[me].y) res = "L";
        }
        else
        {
          // you を me のいるマスに移す
          if (man[you].x < man[me].x) res = "D";
          if (man[me].x < man[you].x) res = "U";
          if (man[you].y < man[me].y) res = "R";
          if (man[me].y < man[you].y) res = "L";
        }
          man[me].reserve(res);
      }
    }
    // 次の行動をふりわける
    vl move_idx;
    vl make_idx;
    vl none_idx;
    rep(i, m)
    {
      if (man[i].isFinish()) continue;
      if (man[i].isHalf())
      {
        man[i].validateRange();
      }

      if (man[i].isMove()) move_idx.pb(i);
      else if (man[i].isMake()) make_idx.pb(i);
      else none_idx.pb(i);
    }
    
    // さきに動く
    for (auto& idx: move_idx)
    {
      // debug("how move? ", idx, man[idx].now());
      out[idx] = man[idx].move();
      // debug("result", out[idx]);
    }
    // つぎにブロックを作る
    for (auto& idx: make_idx)
    {
      // debug("how make? ", idx, man[idx].now());
      out[idx] = man[idx].make(turn > 250);
      // debug("result", out[idx]);
    }

    for (auto& idx: none_idx)
    {
      man[idx].progress++;
    }
    // 今いるマスから退去
    for (auto& [x, y] : remove_list)
    {
      mp[x][y][MAN]--;
    }
    remove_list.clear();

    cout << out << endl;

    rep(i, n)
    {
      string mv;
      cin >> mv;
      pet[i].mv(mv);
    }
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}