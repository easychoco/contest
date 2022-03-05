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
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using P = pair<ll, ll>;
const ll INF = 1LL << 60;
void YN(bool a) { cout << (a ? "Yes" : "No") << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
void show(){ cout << endl; }
template <class Head, class... Tail>
void show(Head&& head, Tail&&... tail){ cout << head << " "; show(std::forward<Tail>(tail)...); }
template<class T> inline void showall(T& a) { for(auto v:a) cout<<v<<" "; cout<<endl; }

void solve()
{
  ll n, m;
  cin >> n >> m;
  vvl graph(n, vl());
  vvl graph_idx(n, vl(n, -1)); // graph_idx[from][to]
  vector<P> input(m);
  vector<ll> prev(n, -1);
  vector<bool> shortest_memo(m, false);
  rep(i, m)
  {
    ll s, t;
    cin >> s >> t;
    s--; t--;
    graph[s].emplace_back(t);
    graph_idx[s][t] = i;
    input[i] = P(s, t);
  }

  vector<ll> d(n, INF);

  // 最短経路を計算
  {
    vector<bool> come(n, false);
    queue<P> que;

    que.push(P(0, 0));
    while(!que.empty())
    {
      auto [now, depth] = que.front();
      que.pop();
      if (come[now]) continue;
      come[now] = true;

      d[now] = depth;
      for (auto to : graph[now])
      {
        if (come[to]) continue;
        if (prev[to] == -1) prev[to] = now;
        que.push(P(to, depth + 1));
      }
    }
  }

  if (d[n - 1] == INF)
  {
    rep(_, m) show(-1);
    return;
  }

  // 最短経路に使う index を保存
  {
    ll idx = n - 1;
    while(prev[idx] != -1)
    {
      ll gi = graph_idx[prev[idx]][idx];
      shortest_memo[gi] = true;
      idx = prev[idx];
    }
  }

  // input ごとに
  rep(i, m)
  {
    // 最短経路に使わないものは最短経路は変わらない
    if (!shortest_memo[i])
    {
      show(d[n - 1]);
      continue;
    }

    // 最短経路に使うものは最短経路を再計算
      ll from, to;
    tie(from, to) = input[i];
    queue<P> que;
    vector<bool> come(n, false);
    que.push(P(0, 0));
    ll ans = -1;
    while(!que.empty())
    {
      auto [now, depth] = que.front();
      que.pop();

      if (come[now]) continue;
      come[now] = true;
      if (now == n - 1)
      {
        ans = depth;
        break;
      }
      for (auto next : graph[now])
      {
        if (come[next]) continue;
        if (now == from && next == to) continue;
        que.push(P(next, depth + 1));
      }
    }
    show(ans);
  }

}

int main()
{
  fastio;
  solve();

  return 0;
}
