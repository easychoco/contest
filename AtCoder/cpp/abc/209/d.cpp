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
  ll n, q;
  cin >> n >> q;
  // tuple<cost, to>
  vector< vector<tuple<ll, ll>> > G(n);
  rep(i, n - 1)
  {
    ll u, v;
    cin >> u >> v;
    u--; v--;
    G[u].emplace_back(1, v);
    G[v].emplace_back(1, u); // 無向グラフの場合
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
    for (const auto& edge : G[now])
    {
      ll cost, to;
      tie(cost, to) = edge;
      if (chmin(d[to], d[now] + cost))
      {
        que.push(P(d[to], to));
      }
    }
  }

  rep(i, q)
  {
    ll ci, di;
    cin >> ci >> di;
    ci--; di--;
    if (abs(d[ci] - d[di]) % 2 == 0)
    {
      show("Town");
    }
    else
    {
      show("Road");
    }
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}
