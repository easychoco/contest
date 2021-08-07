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

vector<int> edge[1010];
bool visited[1010];
void dfs(int v)
{
  if (visited[v]) return;
  visited[v] = true;
  for(auto& to : edge[v])
  {
    dfs(to);
  }
}

void solve()
{
  ll n, m, u, v, w;
  cin >> n >> m;
  //     tuple<from, to, cost>
  vector<tuple<ll, ll, ll>> G(m);
  rep(i, m)
  {
    cin >> u >> v >> w;
    u--; v--;
    G[i] = make_tuple(v, u, -w);
    edge[v].emplace_back(u);
  }

  // dfs で n から到達可能な頂点だけ残す
  dfs(n - 1);

  const ll INF = 1LL << 60;
  vector<ll> d(n, INF);
  d[n - 1] = 0;

  rep(i, n)
  {
    rep(j, m)
    {
      ll from, to, cost;
      tie(from, to, cost) = G[j];
      if (!visited[from]) continue;
      if (chmin(d[to], d[from] + cost))
      {
        if (i == n - 1) //負閉路検出
        {
          cout << "inf";
          return;
        }
      }
    }
  }
  cout << -d[0];
}

int main()
{
  fastio;
  solve();

  return 0;
}