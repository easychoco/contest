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

// https://atcoder.jp/contests/abc237/tasks/abc237_e
void solve()
{
  ll n, m;
  cin >> n >> m;
  vl h(n);
  rep(i, n) cin >> h[i];
  vvp graph(n);

  rep(i, m)
  {
    ll u, v;
    cin >> u >> v;
    u--; v--;

    ll score = h[u] - h[v];
    if (score < 0)
    {
      // u > v とする
      swap(u, v);
      score *= -1;
    }
    graph[u].pb(P(0, v));
    graph[v].pb(P(score, u));
  }

  // dist[i] = i に行くときに上ることになる最小量
  vl dist(n, INF);
  dist[0] = 0;
  priority_queue<P, vp, greater<P>> que;
  que.push(P(0, 0));
  while(que.size())
  {
    auto[cost, now] = que.top();
    que.pop();
    for (auto [nc, next] : graph[now])
    {
      if (chmin(dist[next], cost + nc))
      {
        que.push(P(dist[next], next));
      }
    }
  }

  vl ans(n, INF);
  rep(i, n)
  {
    ans[i] = h[0] - h[i] - dist[i];
  }
  print(*max_element(ALL(ans)));
}

// // https://atcoder.jp/contests/agc020/tasks/agc020_b
// void solve()
// {
//   ll k;
//   cin >> k;
//   vl a(k);
//   rep(i, k) cin >> a[i];

//   auto f = [&](ll arg)
//   {
//     ll now = arg;
//     rep(i, k)
//     {
//       now = (now / a[i]) * a[i];
//     }
//     return now;
//   };

//   ll mn, mx;
//   {
//     // はじめに arg人いて、最後に 2人以上残るか
//     ll wa = 0, ac = 2'000'000'000'000'000'000LL;
//     while(ac - wa > 1)
//     {
//       ll wj = (ac + wa) / 2;
//       if ( f(wj) >= 2 ) ac = wj;
//       else wa = wj;
//     }

//     if (f(ac) != 2)
//     {
//       print(-1);
//       return;
//     }
//     mn = ac;
//   }
//   {
//     // はじめに arg人いて、最後に 2人以下残るか
//     ll ac = 2, wa = 2'000'000'000'000'000'000LL;
//     while(wa - ac > 1)
//     {
//       ll wj = (ac + wa) / 2;
//       if ( f(wj) <= 2 ) ac = wj;
//       else wa = wj;
//     }
//     if (f(ac) != 2)
//     {
//       print(-1);
//       return;
//     }
//     mx = ac;
//   }

//   print(mn, mx);
// }

// // https://atcoder.jp/contests/abc144/tasks/abc144_e
// void solve()
// {
//   ll n, k;
//   cin >> n >> k;
//   vl a(n), f(n);
//   rep(i, n) cin >> a[i];
//   rep(i, n) cin >> f[i];

//   sort(ALL(a));
//   sort(RALL(f));

//   // 合計で k 減らすことで、最大値を arg 以下にすることができるか
//   auto judge = [&](ll arg) -> bool
//   {
//     ll cost = 0;
//     rep(i, n)
//     {
//       cost += max((ll)0, a[i] - arg / f[i]);
//     }
//     return cost <= k;
//   };

//   ll wa = -1, ac = 1'000'000'000'000'000LL;
//   while(ac - wa > 1)
//   {
//     ll wj = (ac + wa) / 2;
//     if ( judge(wj) ) ac = wj;
//     else wa = wj;
//   }

//   print(ac);
// }

int main()
{
  fastio;
  solve();

  return 0;
}
