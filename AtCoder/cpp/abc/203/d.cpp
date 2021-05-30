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
  ll n, k;
  cin >> n >> k;
  vector<vector<ll>> mp(n, vector<ll>(n));
  rep(y, n) rep(x, n) cin >> mp[y][x];

  auto f = [&](ll arg) -> bool
  {
    // arg 以上の値が k * k / 2 + 1 個以上あるかどうか
    // そのとき、 中央値は arg 以下になる
    vector<vector<ll>> sum(n + 1, vector<ll>(n + 1, 0));
    rep(y, n) rep(x, n) sum[y + 1][x + 1] = sum[y][x + 1] + sum[y + 1][x] - sum[y][x] + ((mp[y][x] >= arg) ? 1 : 0);

    ll cnt = 1LL << 60;
    rep(y, n - k + 1) rep(x, n - k + 1)
    {
      ll x1, x2, y1, y2;
      y1 = y;
      y2 = y + k;
      x1 = x;
      x2 = x + k;
      chmin (cnt, sum[y2][x2] - sum[y1][x2] - sum[y2][x1] + sum[y1][x1]);
    }
    return k * k / 2 + 1 <= cnt;
  };
  ll ac = 0, wa = 1'000'000'001LL;
  while(wa - ac > 1)
  {
    ll wj = (ac + wa) / 2;
    if ( f(wj) ) ac = wj;
    else wa = wj;
  }
  show(ac);
}

int main()
{
  fastio;
  solve();

  return 0;
}