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

void solve()
{
  ll h, w;
  cin >> h >> w;

  vs mp(h);
  rep(i, h) cin >> mp[i];

  vvl able(h, vl(w, 1));

  // 横
  rep(y, h)
  {
    // 右
    bool ok = false;
    rep(x, w)
    {
      if (mp[y][x] != '.') ok = false;
      if (ok) able[y][x] = 0;
      if (mp[y][x] == '>') ok = true;
    }
    // 左
    ok = false;
    rrep(x, w - 1)
    {
      if (mp[y][x] != '.') ok = false;
      if (ok) able[y][x] = 0;
      if (mp[y][x] == '<') ok = true;
    }
  }

  // 縦
  rep(x, w)
  {
    // 下
    bool ok = false;
    rep(y, h)
    {
      if (mp[y][x] != '.') ok = false;
      if (ok) able[y][x] = 0;
      if (mp[y][x] == 'v') ok = true;
    }
    // 上
    ok = false;
    rrep(y, h - 1)
    {
      if (mp[y][x] != '.') ok = false;
      if (ok) able[y][x] = 0;
      if (mp[y][x] == '^') ok = true;
    }
  }

  ll sx = -1, sy = -1;
  ll gx = -1, gy = -1;
  rep(y, h)
  rep(x, w)
  {
    if (mp[y][x] == 'S')
    {
      sx = x;
      sy = y;
    }
    else if (mp[y][x] == 'G')
    {
      gx = x;
      gy = y;
    }
    else if (mp[y][x] != '.') able[y][x] = 0;
  }

  const vl dx { 0, 1, 0, -1 };
  const vl dy { 1, 0, -1, 0 };

  vvl score(h, vl(w, -1));
  score[sy][sx] = 0;
  queue<P> que;
  que.push(make_pair(sy, sx));
  while(que.size())
  {
    auto [y, x] = que.front();
    que.pop();

    rep(i, 4) 
    {
      ll ny = y + dy[i];
      ll nx = x + dx[i];

      if (ny < 0 || h <= ny) continue;
      if (nx < 0 || w <= nx) continue;
      if (able[ny][nx] == 0) continue;
      if (score[ny][nx] != -1) continue;

      score[ny][nx] = score[y][x] + 1;
      que.push(make_pair(ny, nx));
    }
  }

  print(score[gy][gx]);
}

int main()
{
  fastio;
  solve();

  return 0;
}
