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

ll n, k;
vector<string> mp;
set<vector<ll>> st;
set<vector<ll>> ans;
const ll dy[4] = { 0, -1, 0, 1 };
const ll dx[4] = { 1, 0, -1, 0 };

void dfs(vl m)
{
  if ((ll)m.size() == k)
  {
    ans.insert(m);
    return;
  }
  if (st.find(m) != st.end()) return;
  st.insert(m);
  for(auto& vi: m)
  {
    ll x = vi % n;
    ll y = vi / n;
    rep(i, 4)
    {
      ll ny = y + dy[i];
      ll nx = x + dx[i];
      if (ny < 0 || n <= ny) continue;
      if (nx < 0 || n <= nx) continue;
      if (mp[ny][nx] == '#') continue;
      ll idx = ny * n + nx;
      if (*lower_bound(ALL(m), idx) == idx) continue;

      vl nm = m;
      nm.emplace_back(idx);
      sort(ALL(nm));
      dfs(nm);
    }
  }
}

void solve()
{
  cin >> n >> k;
  mp.resize(n);
  rep(i, n) cin >> mp[i];

  rep(y, n) rep(x, n)
  {
    if (mp[y][x] == '#') continue;
    vl m { y * n + x };
    dfs(m);
  }
  show(ans.size());
}

int main()
{
  fastio;
  solve();

  return 0;
}