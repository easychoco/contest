// https://atcoder.jp/contests/nikkei2019-2-qual/tasks/nikkei2019_2_qual_d
#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i=a;i<(ll)n;++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()

using namespace std;
using ll = long long;
using P = pair<ll, ll>;
void YN(bool a) { cout << (a ? "Yes" : "No") << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
void show(){ cout << endl; }
template <class Head, class... Tail>
void show(Head&& head, Tail&&... tail){ cout << head << " "; show(std::forward<Tail>(tail)...); }
template<class T> inline void showall(T& a) { for(auto v:a) cout<<v<<" "; cout<<endl; }

struct Edge{ ll cost, to; };

void solve()
{
  ll n, m;
  cin >> n >> m;
  vector< vector<Edge> > edge(n, vector<Edge>());
  rep(i, m)
  {
    ll l, r, c;
    cin >> l >> r >> c;
    l--; r--;
    edge[l].emplace_back(Edge{c, r});
  }

  rep(i, n)
  {
    if (i + 1 < n) edge[i + 1].emplace_back(Edge{0, i});
  }
  
  const ll INF = 1LL << 60;
  vector<ll> d(n, INF);
  d[0] = 0;
  priority_queue<P, vector<P>, greater<P>> que;
  que.push(P(0, 0)); // P(cost, start)
  while (!que.empty())
  {
    P p = que.top();
    que.pop();
    ll now = p.second;
    if (d[now] < p.first) continue;
    for (const auto& e : edge[now])
    {
      if (d[e.to] > d[now] + e.cost)
      {
        d[e.to] = d[now] + e.cost;
        que.push(P(d[e.to], e.to));
      }
    }
  }
  if (d[n - 1] == INF) d[n - 1] = -1;
  show(d[n - 1]);
}

int main()
{
  fastio;
  solve();

  return 0;
}