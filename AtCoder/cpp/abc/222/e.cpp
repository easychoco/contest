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

using namespace std;
using namespace atcoder;
using ll = int_fast64_t;
using vl = vector<ll>;
using vvl = vector<vl>;
using P = pair<ll, ll>;
using vp = vector<P>;
using vvp = vector<vp>;
const ll INF = 1LL << 60;
void YN(bool a) { cout << (a ? "Yes" : "No") << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
void show(){ cout << endl; }
template <class Head, class... Tail>
void show(Head&& head, Tail&&... tail){ cout << head << " "; show(std::forward<Tail>(tail)...); }
template<class T> inline void showall(T& a) { for(auto v:a) cout<<v<<" "; cout<<endl; }

using mint = modint998244353;

// from から to への最短経路を計算する O(edge_num)
// graph[from] = P(to, idx)
// use_cnt[idx] = idx の枝が使われる回数
// cf. ABC222-E
void bfs_shortest_path(vector< vector<P> >& graph, vl& use_cnt, ll from, ll to)
{
  ll sz = graph.size();
  queue<P> que;
  que.push(P(from, -1));
  vector<P> prev(sz, P(-1, -1));
  vector<bool> come(sz, false);
  while(!que.empty())
  {
    auto [now, _] = que.front();
    que.pop();
    if (now == to) break;
    come[now] = true;
    for (auto [next, idx]: graph[now])
    {
      if (come[next]) continue;
      que.push(P(next, idx));
      prev[next] = P(now, idx);
    }
  }

  ll now = to;
  while(now != from)
  {
    auto [next_rev, idx] = prev[now];
    now = next_rev;
    use_cnt[idx]++;
  }
}

void solve()
{
  ll n, m, k;
  cin >> n >> m >> k;
  vl a(m);
  vector< vector<P> > graph(n, vector<P>());
  rep(i, m) { cin >> a[i]; a[i]--; }
  rep(i, n - 1)
  {
    ll u, v;
    cin >> u >> v;
    u--; v--;
    graph[u].emplace_back(v, i);
    graph[v].emplace_back(u, i);
  }
  
  vl use_cnt(n - 1, 0);
  repi(i, 1, m)
  {
    bfs_shortest_path(graph, use_cnt, a[i - 1], a[i]);
  }

  ll sum = accumulate(ALL(use_cnt), 0LL);
  if (abs(k) > sum)
  {
    show(0);
    return;
  }

  sort(ALL(use_cnt));
  ll sumv = 0;

  // dp[i] = 和が i になる数
  vector<mint> dp(2 * sum + 1, 0);
  dp[sum] = 1;
  repi(i, 1, n)
  {
    vector<mint> dp_next(2 * sum + 1, 0);
    sumv += use_cnt[i - 1];
    repie(j, sum - sumv, sum + sumv)
    {
      if (j + use_cnt[i - 1] <= sum * 2) dp_next[j + use_cnt[i - 1]] += dp[j];
      if (0 <= j - use_cnt[i - 1])       dp_next[j - use_cnt[i - 1]] += dp[j];
    }
    dp = dp_next;
  }
  show(dp[k + sum].val());
}

int main()
{
  fastio;
  solve();

  return 0;
}
