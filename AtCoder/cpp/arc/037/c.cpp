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
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n), b(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];

  sort(ALL(a));
  sort(ALL(b));

  auto f = [&](ll arg)
  {
    ll cnt = 0;
    rep(i, n)
    {
      // a[i] * b[wj] が arg 未満の数字がac+1個
      ll ac = -1, wa = n;
      while(wa - ac > 1)
      {
        ll wj = (ac + wa) / 2;
        if ( a[i] * b[wj] < arg ) ac = wj;
        else wa = wj;
      }
      cnt += ac + 1;
    }
    return cnt < k;
  };

  // wj未満の数がk個未満
  // waについて
  // ok : wa = 1'000'000'000'000'000'001;
  // ng : wa = 1e18 + 5 にすると丸め誤差で死ぬ
  ll ac = 1, wa = (ll)1e18 + 5;
  while(wa - ac > 1)
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