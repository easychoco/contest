#include <bits/stdc++.h>
#include <atcoder/all>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i=a;i<(ll)n;++i)
#define repe(i,n) repie(i,0,n)
#define repie(i,a,n) for(ll i=a;i<=(ll)n;++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()

using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<ll, ll>;
void YN(bool a) { cout << (a ? "Yes" : "No") << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
void show(){ cout << endl; }
template <class Head, class... Tail>
void show(Head&& head, Tail&&... tail){ cout << head << " "; show(std::forward<Tail>(tail)...); }
template<class T> inline void showall(T& a) { for(auto v:a) cout<<v<<" "; cout<<endl; }

void solve()
{
  ll n, m, u, v, w;
  cin >> n >> m;
  // tuple<cost, to>
  vector< vector<tuple<ll, ll>> > G(n);
  rep(i, m)
  {
    cin >> u >> v >> w;
    u--; v--;
    G[u].emplace_back(w, v);
    G[v].emplace_back(w, u); // 無向グラフの場合
  }

  const ll INF = 1LL << 60;
  ll start[2] = { 0, n - 1 };
  vector<vector<ll> > d(2, vector<ll>(n, INF));
  rep(i, 2)
  {
    d[i][start[i]] = 0;
    priority_queue<P, vector<P>, greater<P>> que;
    que.push(P(0, start[i])); // P(cost, start)
    while (!que.empty())
    {
      P p = que.top();
      que.pop();
      ll now = p.second;
      if (d[i][now] < p.first) continue;
      for (const auto& edge : G[now])
      {
        ll cost, to;
        tie(cost, to) = edge;
        if (chmin(d[i][to], d[i][now] + cost))
        {
          que.push(P(d[i][to], to));
        }
      }
    }
  }

  rep(i, n)
  {
    show(d[0][i] + d[1][i]);
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}