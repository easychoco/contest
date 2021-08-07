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
  ll n;
  cin >> n;
  vector<ll> a(n), t(n);
  rep(i, n)
  {
    cin >> a[i] >> t[i];
  }

  auto f = [&](ll x)
  {
    rep(i, n)
    {
      if (t[i] == 1)
      {
        x += a[i];
      }
      else if (t[i] == 2)
      {
        chmax(x, a[i]);
      }
      else
      {
        chmin(x, a[i]);
      }
    }    
    return x;
  };

  ll lev = f(-1'000'000'000LL);
  ll rev = f( 1'000'000'001LL);

  ll le, re;

  ll ac = -1'000'000'000LL, wa = 1'000'000'001LL;
  while(wa - ac > 1)
  {
    ll wj = (ac + wa) / 2;
    if ( f(wj) == lev ) ac = wj;
    else wa = wj;
  }

  le = ac;

  ac = -1'000'000'000LL, wa = 1'000'000'001LL;
  while(wa - ac > 1)
  {
    ll wj = (ac + wa) / 2;
    if ( f(wj) == rev ) wa = wj;
    else ac = wj;
  }

  re = wa;

  ll q;
  cin >> q;
  if (lev == rev)
  {
    rep(qi, q) show(lev);
    return;
  }

  rep(qi, q)
  {
    ll x;
    cin >> x;
    ll ans;
    if (x <= le) ans = lev;
    else if (re <= x) ans = rev;
    else ans = lev + x - le;
    show(ans);
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}