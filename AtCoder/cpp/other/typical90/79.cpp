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
  ll h, w;
  cin >> h >> w;
  vector< vector<ll> > mpa(h, vector<ll>(w, 0));
  vector< vector<ll> > mpb(h, vector<ll>(w, 0));
  rep(y, h) rep(x, w) cin >> mpa[y][x];
  rep(y, h) rep(x, w) cin >> mpb[y][x];

  ll ans = 0;
  rep(y, h - 1)
  rep(x, w - 1)
  {
    ll cnt = mpb[y][x] - mpa[y][x];
    mpa[y][x] += cnt;
    mpa[y + 1][x] += cnt;
    mpa[y][x + 1] += cnt;
    mpa[y + 1][x + 1] += cnt;
    ans += abs(cnt);
  }
  if (mpa == mpb)
  {
    YN(true);
    show(ans);
  }
  else
  {
    YN(false);
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}