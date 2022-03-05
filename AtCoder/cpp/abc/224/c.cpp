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
using ll = int_fast64_t;
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

/*
3頂点が同一直線状にあったらNG
-> 2線分の傾きが一致したらNG
*/
void solve()
{
  ll n;
  cin >> n;
  vp pos(n);
  rep(i, n)
  {
    ll x, y;
    cin >> x >> y;
    pos[i] = P(x, y);
  }

  ll ans = 0;
  rep(i1, n)
  rep(i2, i1)
  rep(i3, i2)
  {
    auto [x1, y1] = pos[i1];
    auto [x2, y2] = pos[i2];
    auto [x3, y3] = pos[i3];
    // if ((x2 - x1) / (y2 - y1) == (x3 - x1) / (y3 - y1))
    if ((x2 - x1) * (y3 - y1) != (x3 - x1) * (y2 - y1)) ans++;
  }
  show(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}
