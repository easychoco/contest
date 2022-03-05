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

ll start_size = 0;
ll start_sum = 0;
ll n;

vector< vector<P> > graph;
vector<P> sz;
vector<bool> come;

void dfs(ll now)
{
  come[now] = true;
  start_sum += start_size;

  start_size++;
  for (auto [next, idx] : graph[now])
  {
    if (come[next]) continue;
    sz[idx] = P(start_size, n - start_size);
    dfs(next);
  }
  start_size--;
}


void solve()
{
  cin >> n;
  graph.resize(n, vector<P>());
  come.resize(n, false);
  sz.resize(n - 1);
  rep(i, n - 1)
  {
    ll u, v;
    cin >> u >> v;
    u--; v--;
    graph[u].emplace_back(v, i);
    graph[v].emplace_back(u, i);
  }

  ll start = 0;
  rep(i, n) if (graph[i].size() == 1) start = i;
  dfs(start);
  show(start);
  rep(i, n - 1) show(sz[i].first, sz[i].second);
}

int main()
{
  fastio;
  solve();

  return 0;
}
