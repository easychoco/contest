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

using mint = modint998244353;

void solve()
{
  ll n, m, k;
  cin >> n >> m >> k;
  vvl graph(n);
  rep(i, m)
  {
    ll u, v;
    cin >> u >> v;
    u--; v--;
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
  }

  vector<mint> dp(n, 0);
  vector<mint> next(n, 0);
  dp[0] = 1;
  rep(_, k)
  {
    // 余事象で解く
    mint sum = accumulate(ALL(dp), mint(0));

    rep(i, n)
    {
      next[i] = sum - dp[i];
      for (auto to: graph[i])
      {
        next[i] -= dp[to];
      }
    }
    dp = next;
  }
  show(dp[0].val());  
}

int main()
{
  fastio;
  solve();

  return 0;
}
