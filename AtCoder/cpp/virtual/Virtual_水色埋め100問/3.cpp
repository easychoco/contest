// https://atcoder.jp/contests/abc148/tasks/abc148_f
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
  int n, u, v, a, b;
  cin >> n >> u >> v;
  u--; v--;
  vector< vector<Edge> > tree(n, vector<Edge>());
  rep(i, n - 1)
  {
    cin >> a >> b;
    a--; b--;
    tree[a].emplace_back(Edge({1, b}));
    tree[b].emplace_back(Edge({1, a}));
  }

  const ll INF = 1LL << 60;

  vector<vector<ll>> d(2, vector<ll>(n, INF));
  int start[2] = {u, v};
  rep(ii, 2)
  {
    priority_queue<P, vector<P>, greater<P>> que;
    que.push(P(0, start[ii])); // P(cost, start)
    d[ii][start[ii]] = 0;
    while (!que.empty())
    {
      P p = que.top();
      que.pop();
      ll node = p.second;
      if (d[ii][node] < p.first) continue;
      for (const auto& edge : tree[node])
      {
        if (d[ii][edge.to] > d[ii][node] + edge.cost)
        {
          d[ii][edge.to] = d[ii][node] + edge.cost;
          que.push(P(d[ii][edge.to], edge.to));
        }
      }
    }
  }
  
  vector<ll> dist(n);
  rep(i, n)
  {
    if (d[0][i] < d[1][i]) dist[i] = d[1][i];
    else dist[i] = 0;
  }

  cout << *max_element(ALL(dist)) - 1 << endl;
}

int main()
{
  fastio;
  solve();

  return 0;
}