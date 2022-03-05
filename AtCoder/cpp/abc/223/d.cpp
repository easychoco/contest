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
using ll = int_fast64_t;
using vl = vector<ll>;
using vvl = vector<vl>;
using P = pair<ll, ll>;
using vp = vector<P>;
using vvp = vector<vp>;
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
  ll n, m;
  cin >> n >> m;

  vector< vector<ll> > edge(n, vector<ll>()); // グラフ・DAG
  vector<ll> deg(n, 0); // 入り次数
  rep(i, m)
  {
    ll a, b;
    cin >> a >> b;
    a--; b--;
    edge[a].emplace_back(b);
    deg[b]++;
  }

  vector<ll> sorted;
  priority_queue<ll, vector<ll>, greater<ll>> que;
  rep(i, n) if (deg[i] == 0) que.push(i);
  while(!que.empty())
  {
    ll now = que.top();
    que.pop();
    sorted.emplace_back(now + 1);
    for(const auto& to : edge[now])
    {
      deg[to]--;
      if (deg[to] == 0) que.push(to);
    }
  }

  if (sorted.size() < n)
  {
    show(-1);
  }
  else
  {
    showall(sorted);
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}
