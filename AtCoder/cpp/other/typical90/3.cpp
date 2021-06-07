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

  ll st = 0;
  ll ans = 0;
  rep(i, 2)
  {
    queue<tuple<ll, ll>> que;
    que.emplace(st, 0);
    vector<bool> come(n, false);
    while(!que.empty())
    {
      ll now, depth;
      tie(now, depth) = que.front();
      que.pop();
      if (come[now]) continue;
      come[now] = true;

      if (chmax(ans, depth)) st = now;

      for(auto& next : graph[now])
      {
        que.emplace(next, depth + 1);
      }
    }
  }
  show(ans + 1);
}

int main()
{
  fastio;
  solve();

  return 0;
}