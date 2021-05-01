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
  ll r, c;
  cin >> r >> c;
  vector< vector<ll> > a(r, vector<ll>(c - 1));
  vector< vector<ll> > b(r - 1, vector<ll>(c));
  rep(y, r) rep(x, c - 1) cin >> a[y][x];
  rep(y, r - 1) rep(x, c) cin >> b[y][x];

  // tuple<cost, to>
  vector< vector<tuple<ll, ll>> > graph(r * c);
  rep(y, r) rep(x, c)
  {
    ll idx = y * c + x % c;

    // 左
    if (x % c > 0)
    {
      ll ni = idx - 1;
      ll cost = a[y][x - 1];
      graph[idx].emplace_back(cost, ni);
    }

    // 右
    if (x % c < c - 1)
    {
      ll ni = idx + 1;
      ll cost = a[y][x];
      graph[idx].emplace_back(cost, ni);
    }

    // 上
    if (y < r - 1)
    {
      ll ni = idx + c;
      ll cost = b[y][x];
      graph[idx].emplace_back(cost, ni);
    }
  }

  const ll INF = 1LL << 60;
  vector<ll> d(r * c, INF);
  d[0] = 0;
  priority_queue<P, vector<P>, greater<P>> que;
  que.push(P(0, 0)); // P(cost, start)
  while (!que.empty())
  {
    P p = que.top();
    que.pop();
    ll now = p.second;
    if (d[now] < p.first) continue;
    for (const auto& edge : graph[now])
    {
      ll cost, to;
      tie(cost, to) = edge;
      if (d[to] > d[now] + cost)
      {
        d[to] = d[now] + cost;
        que.push(P(d[to], to));
      }
    }
    repi(i, 1, r)
    {
      ll to = now - c * i;
      if (to < 0) break;
      ll cost = 1 + i;
      if (d[to] > d[now] + cost)
      {
        d[to] = d[now] + cost;
        que.push(P(d[to], to));
      }
    }
  }
  show(d[r * c - 1]);
}

int main()
{
  fastio;
  solve();

  return 0;
}