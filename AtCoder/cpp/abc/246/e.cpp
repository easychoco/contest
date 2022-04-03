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
constexpr ll INF = 1LL << 60;
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
void debug() { cerr << endl; }
template <class Head, class... Tail>
void debug(Head&& head, Tail&&... tail){ cerr << head << " "; debug(std::forward<Tail>(tail)...); }

void solve()
{
  ll n, ay, ax, by, bx;
  cin >> n >> ay >> ax >> by >> bx;

  if (((ay + ax) & 1) + ((by + bx) & 1) == 1)
  {
    print(-1);
    return;
  }

  ay--; ax--; by--; bx--;

  vector<string> mp(n);
  rep(i, n) cin >> mp[i];

  vvl dist(n, vl(n, INF));
  vvl dire(n, vl(n, 0));
  // direction(mask):
  //   左下 - 右上: 1
  //   左上 - 右下: 2
  dist[ay][ax] = 0;

  ll dx[4] = {  1, -1,  1, -1 };
  ll dy[4] = { -1,  1,  1, -1 };

  queue<T> que;
  que.push(T(ay, ax, 1));
  que.push(T(ay, ax, 2));
  while(!que.empty())
  {
    auto [y, x, dir] = que.front();
    que.pop();

    dire[y][x] |= dir;
    ll dis = dist[y][x] + 1;
    ll diff = 2 * (dir == 2);
    rep(i, 2)
    {
      ll ny = y;
      ll nx = x;
      while(1)
      {
        ny += dy[diff + i];
        nx += dx[diff + i];
        if (ny < 0 || ny >= n) break;
        if (nx < 0 || nx >= n) break;
        if (mp[ny][nx] == '#') break;
        if (dire[ny][nx] & dir) break;

        dire[ny][nx] |= dir;
        if (chmin(dist[ny][nx], dis))
        {
          que.push(T(ny, nx, 3 ^ dir));
        }
      }
    }
  }
  if (dist[by][bx] == INF) dist[by][bx] = -1;
  print(dist[by][bx]);
}

int main()
{
  fastio;
  solve();

  return 0;
}
