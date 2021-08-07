// https://atcoder.jp/contests/abc146/tasks/abc146_d
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
  vector< vector<P> > edge(n, vector<P>());

  rep(i, n - 1)
  {
    ll a, b;
    cin >> a >> b;
    a--; b--;
    edge[a].emplace_back(b, i);
    edge[b].emplace_back(a, i);
  }

  ll c = 0;
  rep(i, n - 1) chmax(c, (ll)edge[i].size());

  vector<ll> ans(n, -1);

  vector<bool> come(n, false);
  queue<P> que;
  que.emplace(0, -1);

  while(!que.empty())
  {
    ll now, color;
    tie(now, color) = que.front();
    que.pop();

    if (come[now]) continue;
    come[now] = true;

    vector<bool> used_c(c, false);
    if (color >= 0) used_c[color] = true;
    ll nc = 0;
    for(auto e : edge[now])
    {
      ll to, idx; 
      tie(to, idx) = e;
      if (come[to]) continue;

      while(used_c[nc]) nc++;
      used_c[nc] = true;
      ans[idx] = nc;
      que.emplace(to, nc);
    }
  }

  show(c);
  rep(i, n - 1)
  {
    show(ans[i] + 1);
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}