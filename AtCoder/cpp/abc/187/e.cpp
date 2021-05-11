#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i=a;i<(ll)n;++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define Show(val) cout<<(val)<<" "
#define Showln(val) cout<<(val)<<endl

using namespace std;
using ll = long long;
using P = pair<ll, ll>;
// using P = pair<int, int>;
void YN(bool a) { cout << (a ? "Yes" : "No"); }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

struct Edge{ ll cost, to; };
void solve()
{
  ll n, a, b;
  cin >> n;
  vector<tuple<ll, ll>> edge(n - 1);
  vector< vector<ll> > G(n, vector<ll>());
  rep(i, n - 1)
  {
    cin >> a >> b;
    a--; b--;
    edge[i] = make_tuple(a, b);
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }

  ll d = 0;
  vector<ll> dist(n, 0);
  vector<bool> visited(n, false);
  queue<int> que;
  que.push(0); //初期位置
  while(!que.empty())
  {
    d++;
    int now = que.front();
    que.pop();
    visited[now] = true;
    for(const auto& to : G[now])
    {
      if (visited[to]) continue;
      que.push(to);
      dist[to] = d;
    }
  }

  ll q, t, e, x;
  cin >> q;
  vector<ll> score(n, 0);
  rep(i, q)
  {
    cin >> t >> e >> x;
    e--;
    tie(a, b) = edge[e];
    if (t == 1)
    { // a から b を通らない
      if (dist[a] < dist[b])
      { // a のほうが 0 に近い
        score[0] += x;
        score[b] -= x;
      }
      else
      { // b のほうが 0 に近い
        score[a] += x;
      }
    }
    else
    { // b から a を通らない
      if (dist[a] < dist[b])
      { // a のほうが 0 に近い
        score[b] += x;
      }
      else
      { // b のほうが 0 に近い
        score[0] += x;
        score[a] -= x;
      }
    }
  }

  fill(ALL(visited), false);
  que.push(0); //初期位置
  while(!que.empty())
  {
    int now = que.front();
    que.pop();
    visited[now] = true;
    for(const auto& to : G[now])
    {
      if (visited[to]) continue;
      que.push(to);
      score[to] += score[now];
    }
  }

  rep(i, n)
  {
    cout << score[i] << endl;
  }

}

int main()
{
  fastio;
  solve();

  return 0;
}