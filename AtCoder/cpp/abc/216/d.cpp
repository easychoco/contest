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

void solve()
{
  ll n, m;
  cin >> n >> m;
  vector<queue<ll>> tu(m);
  rep(pos, m)
  {
    ll k;
    cin >> k;
    rep(i, k)
    {
      ll a;
      cin >> a;
      a--;
      tu[pos].push(a);
    }
  }

  vvl pos(n, vl(0));
  rep(i, m) pos[tu[i].front()].emplace_back(i);
  queue<ll> que;
  rep(i, n)
  {
    if ((ll)pos[i].size() == 2) que.push(i);
  }

  while (!que.empty())
  {
    ll now = que.front();
    que.pop();
    for (auto p : pos[now])
    {
      tu[p].pop();
      if (tu[p].empty()) continue;

      ll next = tu[p].front();
      pos[next].emplace_back(p);
      if (pos[next].size() == 2)
      {
        que.push(next);
      }
    }
  }

  rep(i, m)
  {
    if (!tu[i].empty())
    {
      YN(0);
      return;
    }
  }
  YN(1);
}

int main()
{
  fastio;
  solve();

  return 0;
}
