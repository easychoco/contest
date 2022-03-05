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
  ll n;
  cin >> n;
  vector<string> s(n), t(n);
  rep(i, n) cin >> s[i];
  rep(i, n) cin >> t[i];

  rep(_, 4)
  {
    vector<P> sp, tp;
    ll sy, sx, ty, tx;
    sy = sx = ty = tx = INF;
    rep(y, n)
    rep(x, n)
    {
      if (s[y][x] == '#')
      {
        chmin(sy, y);
        chmin(sx, x);
        sp.emplace_back(P(y, x));
      }
      if (t[y][x] == '#')
      {
        chmin(ty, y);
        chmin(tx, x);
        tp.emplace_back(P(y, x));
      }
    }

    sort(ALL(sp));
    sort(ALL(tp));
    for (auto& p : sp)
    {
      p = P(p.first - sy, p.second - sx);
    }
    for (auto& p : tp)
    {
      p = P(p.first - ty, p.second - tx);
    }

    if (sp == tp)
    {
      YN(1);
      return;
    }
    
    vector<string> ns(n, string(n, ' '));
    rep(y, n)
    rep(x, n)
    {
      ns[y][x] = s[x][n - y - 1];
    }
    s = ns;
  }
  YN(0);
}

int main()
{
  fastio;
  solve();

  return 0;
}
