#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i=a;i<(ll)n;++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define Show(val) cout<<(val)<<" "
#define Showln(val) cout<<(val)<<endl

using namespace std;
using ll = long long;
using P = pair<ll, ll>;
// using P = pair<int, int>;
void YN(bool a) { cout << (a ? "Yes" : "No"); }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

void solve()
{
  ll n, a, b;
  cin >> n >> a >> b;
  vector<ll> h(n);
  rep(i, n) cin >> h[i];

  auto f = [&](ll arg)
  {
    vector<ll> tmp(h);
    ll cnt = 0;
    ll cmn_dmg = arg * b;
    rep(i, n)
    {
      tmp[i] -= cmn_dmg;
      if (tmp[i] > 0) cnt += (tmp[i] - 1) / (a - b) + 1;
    }
    return cnt <= arg;
  };

  // wj回以内の爆破で敵を倒せるか
  ll wa = 0, ac = 1000'000'000LL;
  while(ac - wa > 1)
  {
    ll wj = (ac + wa) / 2;
    if ( f(wj) ) ac = wj;
    else wa = wj;
  }

  cout << ac << endl;
}

int main()
{
  fastio;
  solve();

  return 0;
}