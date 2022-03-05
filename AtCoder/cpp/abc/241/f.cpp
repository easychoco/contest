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
void debug() { cerr << endl; }
template <class Head, class... Tail>
void debug(Head&& head, Tail&&... tail){ cerr << head << " "; debug(std::forward<Tail>(tail)...); }

void solve()
{
  ll h, w, n;
  cin >> h >> w >> n;

  // x と y が問題文と逆だけどこれでいい
  ll sy, sx, gy, gx;
  cin >> sy >> sx >> gy >> gx;

  map<ll, vl> my; // (y, x) の y が key
  map<ll, vl> mx; // (y, x) の x が key
  rep(i, n)
  {
    ll y, x;
    cin >> y >> x;
    my[y].pb(x);
    mx[x].pb(y);
  }

  for (auto& v : my)
  {
    sort(ALL(v.second));
  }
  for (auto& v : mx)
  {
    sort(ALL(v.second));
  }

  map<P, ll> score;
  const P sp = P(sy, sx);
  const P gp = P(gy, gx);

  queue<P> que;
  que.push(sp);
  score[sp] = 0;
  while(!que.empty())
  {
    P now = que.front();
    que.pop();
    if (score.find(now) == score.end()) continue;

    ll score_now = score[now];

    if (now == gp)
    {
      print(score_now);
      return;
    }

    auto [y, x] = now;
    
    // 縦
    // 上
    {
      auto itr = lower_bound(ALL(mx[x]), y);
      if (itr != mx[x].begin())
      {
        itr--;
        P next = P(*itr + 1, x);
        if (score.find(next) == score.end())
        {
          score[next] = score_now + 1;
          que.push(next);
        }
      }
    }

    // 下
    {
      auto itr = upper_bound(ALL(mx[x]), y);
      if (itr != mx[x].end())
      {
        P next = P(*itr - 1, x);
        if (score.find(next) == score.end())
        {
          score[next] = score_now + 1;
          que.push(next);
        }
      }
    }

    // 横
    // 左
    {
      auto itr = upper_bound(ALL(my[y]), x);
      if (itr != my[y].begin())
      {
        itr--;
        P next = P(y, *itr + 1);
        if (score.find(next) == score.end())
        {
          score[next] = score_now + 1;
          que.push(next);
        }
      }
    }

    // 右
    {
      auto itr = upper_bound(ALL(my[y]), x);
      if (itr != my[y].end())
      {
        P next = P(y, *itr - 1);
        if (score.find(next) == score.end())
        {
          score[next] = score_now + 1;
          que.push(next);
        }
      }
    }
  }
  print(-1);
}

int main()
{
  fastio;
  solve();

  return 0;
}
