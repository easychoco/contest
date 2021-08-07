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

vector<ll> num(200010, 0);
vector<ll> ans(200010, 0);
vector< vector<ll> > graph(200010, vector<ll>());
vector< vector<tuple<ll, ll>> > query(200010, vector<tuple<ll, ll>>());
void dfs(ll now, ll depth)
{
  for(auto& t : query[now])
  {
    ll d, idx;
    tie(d, idx) = t;
    ans[idx] = num[d];
  }
  num[depth]++;

  for(auto& next : graph[now])
  {
    dfs(next, depth + 1);
  }

  for(auto& t : query[now])
  {
    ll d, idx;
    tie(d, idx) = t;
    ans[idx] = num[d] - ans[idx];
  }
}

void solve()
{
  ll n;
  cin >> n;
  repi(i, 1, n)
  {
    ll p;
    cin >> p;
    p--;
    graph[p].emplace_back(i);
  }

  ll q;
  cin >> q;
  rep(qi, q)
  {
    ll u, d;
    cin >> u >> d;
    u--;
    query[u].emplace_back(d, qi);
  }  
  
  dfs(0, 0);
  rep(i, q) show(ans[i]);
}

int main()
{
  fastio;
  solve();

  return 0;
}