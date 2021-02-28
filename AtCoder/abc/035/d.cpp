#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i = a;i < (ll)n;++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define SHOW(str,val) cout<<(str)<<" : "<<(val)<<endl;

using namespace std;
using ll = long long;
using P = pair<ll, ll>;
// using P = pair<int, int>;
void YN(bool a) { cout << (a ? "Yes" : "No"); }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true;} return false;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true;} return false;}

struct Edge{ ll cost, to; };

void solve()
{
  ll n, m, t, a, b, c;
  cin >> n >> m >> t;
  vector<ll> score(n);
  vector< vector< vector<Edge> > > G(2, vector< vector<Edge> >(n, vector<Edge>()));
  rep(i, n) cin >> score[i];
  rep(i, m)
  {
    cin >> a >> b >> c;
    a--;
    b--;
    G[0][a].emplace_back(Edge{c, b});
    G[1][b].emplace_back(Edge{c, a});
  }

  const ll INF = 1LL << 60;
  vector<vector<ll> > d(2, vector<ll>(n, INF));
  d[0][0] = 0;
  d[1][0] = 0;
  rep(i, 2)
  {
    priority_queue<P, vector<P>, greater<P>> que;
    que.push(P(0, 0)); // P(cost, start)
    while (!que.empty())
    {
      P p = que.top();
      que.pop();
      ll node = p.second;
      if (d[i][node] < p.first) continue;
      for (const auto& edge : G[i][node])
      {
        if (d[i][edge.to] > d[i][node] + edge.cost)
        {
          d[i][edge.to] = d[i][node] + edge.cost;
          que.push(P(d[i][edge.to], edge.to));
        }
      }
    }
  }

  ll ans = 0;
  rep(i, n)
  {
    ll dist = d[0][i] + d[1][i];
    if (dist > INF) continue;
    chmax(ans, (t - dist) * score[i]);
  }
  cout << ans << endl;
}

int main()
{
  fastio;
  solve();

  return 0;
}