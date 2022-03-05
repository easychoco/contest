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
using vvl = vector<vl>;
using P = pair<ll, ll>;
using vp = vector<P>;
using vvp = vector<vp>;
const ll INF = 1LL << 60;
void YN(bool a) { cout << (a ? "Yes" : "No") << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
void show(){ cout << endl; }
template <class Head, class... Tail>
void show(Head&& head, Tail&&... tail){ cout << head << " "; show(std::forward<Tail>(tail)...); }
template<class T> inline void showall(T& a) { for(auto v:a) cout<<v<<" "; cout<<endl; }

using mint = modint998244353;

void solve()
{
  ll h, w, k, x1, y1, x2, y2;
  cin >> h >> w >> k >> x1 >> y1 >> x2 >> y2;

  mint r = 0, s = 0, t = 0, g = 0;
  if (x1 == x2 && y1 == y2) g = 1;
  else if (x1 == x2) s = 1;
  else if (y1 == y2) t = 1;
  else r = 1; 

  // (縦, 横) = (x, y)
  // x に関係するのは h
  // y に関係するのは w
  // ここは逆なので注意

  // rs
  // tg
  rep(i, k)
  {
    mint nr = s * (h - 1) + t * (w - 1) + r * (h + w - 4);
    mint ns = g * (w - 1) + r + s * (w - 2);
    mint nt = g * (h - 1) + r + t * (h - 2);
    mint ng = s + t;
    r = nr;
    s = ns;
    t = nt;
    g = ng;
  }
  show(g.val());
}

int main()
{
  fastio;
  solve();

  return 0;
}
