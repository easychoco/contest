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
  ll n, m;
  cin >> n >> m;
  vvl graph(n);
  vvl graph_inv(n);
  rep(i, m)
  {
    ll u , v;
    cin >> u >> v;
    u--; v--;
    graph[u].pb(v);
    graph_inv[v].pb(u);
  }

  vl visited(n, -1);
  set<ll> loop;
  rep(i, n)
  {
    print(i + 1);
    if (visited[i] >= 0) continue;
    queue<ll> que;
    que.push(i);
    while(!que.empty())
    {
      ll now = que.front();
      que.pop();
      print("come at", now + 1);
      if (visited[now] == i) { loop.insert(now); print("add", now + 1); }
      if (visited[now] >= 0) continue;
      visited[now] = i;
      for (auto next : graph[now]) que.push(next);
    }
  }

  set<ll> ans;
  vb visited_inv(n, false);
  for (auto st : loop)
  {
    queue<ll> que;
    que.push(st);
    while(!que.empty())
    {
      ll now = que.front();
      que.pop();
      if (visited_inv[now]) continue;
      visited_inv[now] = true;
      ans.insert(now);
      for (auto next : graph_inv[now])
      {
        que.push(next);
      }
    }
  }
  print(ans.size());
}

int main()
{
  fastio;
  solve();

  return 0;
}
