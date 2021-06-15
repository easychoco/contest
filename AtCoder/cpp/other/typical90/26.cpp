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
  ll n;
  cin >> n;

  vector< vector<ll> > graph(n, vector<ll>());
  rep(i, n - 1)
  {
    ll a, b;
    cin >> a >> b;
    a--; b--;
    graph[a].emplace_back(b);
    graph[b].emplace_back(a);
  }

  vector<ll> dist[2];
  vector<bool> come(n, false);
  queue<tuple<ll, ll>> que;
  que.emplace(0, 0);
  while(!que.empty())
  {
    ll now, d;
    tie(now, d) = que.front();
    que.pop();
    if (come[now]) continue;
    come[now] = true;
    dist[d % 2].emplace_back(now);
    for (auto& next : graph[now])
    {
      que.emplace(next, d + 1);
    }
  }

  vector<ll> ans;
  if ((ll)dist[0].size() >= n / 2)
  {
    rep(i, n / 2) ans.emplace_back(dist[0][i] + 1);
  }
  else if ((ll)dist[1].size() >= n / 2)
  {
    rep(i, n / 2) ans.emplace_back(dist[1][i] + 1);
  }

  showall(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}