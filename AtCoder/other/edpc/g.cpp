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
  ll n, m;
  cin >> n >> m;
  vector< vector<ll> > edge(n, vector<ll>()); // グラフ・DAG
  vector<ll> deg(n, 0); // 入り次数
  rep(i, m)
  {
    ll x, y;
    cin >> x >> y;
    x--; y--;
    edge[x].emplace_back(y);
    deg[y]++;
  } 

  vector<ll> sorted;
  queue<ll> que;
  rep(i, n) if (deg[i] == 0) que.push(i);
  while(!que.empty())
  {
    ll now = que.front();
    que.pop();
    sorted.emplace_back(now);
    for(const auto& to : edge[now])
    {
      deg[to]--;
      if (deg[to] == 0) que.push(to);
    }
  }

  vector<ll> dp(n, 0);
  rep(i, n)
  {
    ll now = sorted[i];
    for(auto to : edge[now])
    {
      chmax(dp[to], dp[now] + 1);
    }
  }
  show(*max_element(ALL(dp)));
}

int main()
{
  fastio;
  solve();

  return 0;
}