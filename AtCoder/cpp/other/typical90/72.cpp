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

ll h, w;
ll sx, sy;
ll ans = 0;
const ll dx[4] = { 0, 1, 0, -1 };
const ll dy[4] = { 1, 0, -1, 0 };
bool come[20][20];
vector<string> mp;
ll dfs(ll y, ll x)
{
  if (y == sy && x == sx) return 0;
  if (y < 0 || h <= y) return -10000;
  if (x < 0 || w <= x) return -10000;
  if (mp[y][x] == '#') return -10000;
  if (come[y][x]) return -10000;

  ll ret = -10000;
  come[y][x] = true;
  rep(i, 4)
  {
    chmax(ret, 1 + dfs(y + dy[i], x + dx[i]));
  }
  come[y][x] = false;
  return ret;
}

void solve()
{
  cin >> h >> w;
  mp.resize(h);
  rep(i, h) cin >> mp[i];

  ll ans = 0;
  rep(y, h)
  rep(x, w)
  {
    sy = y;
    sx = x;
    if (mp[y][x] == '#') continue;
    rep(i, 4) chmax(ans, dfs(y + dy[i], x + dx[i]));
  }
  show(ans < 2 ? -1 : ans + 1);
}

int main()
{
  fastio;
  solve();

  return 0;
}