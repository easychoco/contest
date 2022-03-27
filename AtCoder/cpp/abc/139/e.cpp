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

// pair を数値に直して、有向グラフにして、
// DAG なら OK
// トポロジカルソートで DAG の判定をしながら、最大経路長を出す

ll to_idx(ll n, ll i1, ll i2)
{
  // i1 < i2 にする
  if (i1 > i2) swap(i1, i2);
  return n * i1 + i2;
}

void solve()
{
  ll n;
  cin >> n;
  ll sz = n * n + 1;
  vvl graph(sz);
  vl deg(sz, 0);
  vl dist(sz, 0);

  rep(now, n)
  {
    vl in;
    rep(_, n - 1)
    {
      ll to;
      cin >> to;
      in.pb(to_idx(n, now, to - 1));
    }
    rep(i, n - 2)
    {
      graph[in[i]].pb(in[i + 1]);
      deg[in[i + 1]]++;
    }
  }

  queue<ll> que;
  rep(i, sz) if (deg[i] == 0) que.push(i);
  ll ok_cnt = que.size();
  while(!que.empty())
  {
    ll now = que.front();
    que.pop();
    for (auto next : graph[now])
    {
      deg[next]--;
      if (deg[next] == 0)
      {
        chmax(dist[next], dist[now] + 1);
        que.push(next);
        ok_cnt++;
      }
    }
  }
  if (ok_cnt < sz)
  {
    print(-1);
    return;
  }
  print(*max_element(ALL(dist)) + 1);
}

int main()
{
	fastio;
	solve();

	return 0;
}