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
#define pb push_back
#define eb emplace_back

using namespace std;
using namespace atcoder;
using vb = vector<bool>;
using vvb = vector<vb>;
using ll = int_fast64_t;
using vl = vector<ll>;
using vvl = vector<vl>;
using P = pair<ll, ll>;
using vp = vector<P>;
using vvp = vector<vp>;
using T = tuple<ll, ll, ll>;
using vt = vector<T>;
const ll INF = 1LL << 60;
void YN(bool a) { cout << (a ? "Yes" : "No") << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
void show(){ cout << endl; }
template <class Head, class... Tail>
void show(Head&& head, Tail&&... tail){ cout << head << " "; show(std::forward<Tail>(tail)...); }
void showd(double d){ cout << std::fixed<<setprecision(13) << d << endl; }
template<class T> inline void showall(T& a) { for(auto v:a) cout<<v<<" "; cout<<endl; }
void debug(){ cerr << endl; }
template <class Head, class... Tail>
void debug(Head&& head, Tail&&... tail){ cerr << head << " "; debug(std::forward<Tail>(tail)...); }

ll n;
vvl aisho;
vb selected;
ll ans = 0, score = 0;
void dfs(ll now, ll depth)
{
  if (depth == n)
  {
    chmax(ans, score);
    return;
  }

  if (selected[now]) return;
  selected[now] = true;
  // debug("select", now);

  repi(you, now + 1, 2 * n)
  {
    if (selected[you]) continue;
    selected[you] = true;
    score ^= aisho[now][you];
    // debug("select", you);
    repi(nx, now + 1, 2 * n) dfs(nx, depth + 1);
    selected[you] = false;
    score ^= aisho[now][you];
    // debug("un-select", you);
  }
  selected[now] = false;
  // debug("un-select", now);
}

void solve()
{
  cin >> n;
  aisho.resize(n * 2, vl(n * 2));
  selected.resize(2 * n, false);
  rep(i1, n * 2 - 1)
  repi(i2, i1 + 1, 2 * n)
  {
    ll score;
    cin >> score;
    aisho[i1][i2] = aisho[i2][i1] = score;
  }

  dfs(0, 0);
  show(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}
