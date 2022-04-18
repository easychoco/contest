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

// https://atcoder.jp/contests/agc024/tasks/agc024_c
void solve()
{
  ll n;
  cin >> n;
  vl a(n);
  rep(i, n)
  {
    cin >> a[i];
  }

  ll ans = 0;
  if (a[0] > 0)
  {
    print(-1);
    return;
  }

  repi(i, 1, n)
  {
    if (a[i - 1] + 1 == a[i])
    {
      ans++;
    }
    else if (a[i - 1] >= a[i])
    {
      ans += a[i];
    }
    else
    {
      print(-1);
      return;
    }
  }
  print(ans);
}

/*
// https://atcoder.jp/contests/abc139/tasks/abc139_e
ll n;
ll toIdx(ll i1, ll i2)
{
  if (i1 > i2) swap(i1, i2);
  return n * i1 + i2;

}
void solve()
{
  cin >> n;
  vvl graph(n * n);
  vl dist(n * n, 0);
  vl deg(n * n, 0);
  rep(i, n)
  {
    vl vi { i };
    rep(j, n - 1)
    {
      ll to;
      cin >> to;
      to--;
      graph[toIdx(i, vi.back())].pb(toIdx(i, to));
      deg[toIdx(i, to)]++;
      vi.pb(to);
    }
  }

  queue<ll> que;
  rep(i, n * n) if (deg[i] == 0) que.push(i);
  while(que.size())
  {
    ll now = que.front();
    que.pop();
    for (auto to : graph[now])
    {
      deg[to]--;
      if (deg[to] == 0)
      {
        que.push(to);
        chmax(dist[to], dist[now] + 1);
      }
    }
  }
  rep(i, n * n)
  {
    if (deg[i] > 0)
    {
      print(-1);
      return;
    }
  }
  print(*max_element(ALL(dist)));
}
*/

/*
// https://atcoder.jp/contests/nikkei2019-qual/tasks/nikkei2019_qual_d
void solve()
{
  ll n, m;
  cin >> n >> m;
  vvl graph(n);
  vl ans(n, 0);
  vl deg(n, 0);
  rep(i, n + m - 1)
  {
    ll u, v;
    cin >> u >> v;
    u--; v--;
    graph[u].pb(v);
    deg[v]++;
  }

  queue<ll> que;
  rep(i, n) if (deg[i] == 0) que.push(i);
  while(que.size())
  {
    ll now = que.front();
    que.pop();
    for (auto to : graph[now])
    {
      deg[to]--;
      if (deg[to] == 0)
      {
        que.push(to);
        ans[to] = now + 1;
      }
    }
  }
  printv(ans);
}
*/

int main()
{
  fastio;
  solve();

  return 0;
}
