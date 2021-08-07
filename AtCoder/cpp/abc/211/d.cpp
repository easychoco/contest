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

using mint = modint1000000007;

void solve()
{
  ll n, m;
  cin >> n >> m;
  vvl graph(n, vl(0));
  rep(i, m)
  {
    ll a, b;
    cin >> a >> b;
    a--; b--;
    graph[a].emplace_back(b);
    graph[b].emplace_back(a);
  }

  vector<mint> dp(n, 0);
  vector<ll> d(n, -1);
  dp[0] = 1;
  d[0] = 0;
  vector<bool> come(n, false);
  queue<P> que;
  que.emplace(0, 1);
  while(!que.empty())
  {
    ll now, depth;
    tie(now, depth) = que.front();
    que.pop();
    if (now == n - 1) break;
    if (come[now]) continue;
    come[now] = true;
    for (auto& next : graph[now])
    {
      if (d[now] == d[next]) continue;
      dp[next] += dp[now];
      d[next] = d[now] + 1;
      que.emplace(next, depth + 1);
    }
  }
  show(dp[n - 1].val());
}

int main()
{
  fastio;
  solve();

  return 0;
}