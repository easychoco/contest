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
  ll n;
  cin >> n;
  vector<ll> h(n), s(n);
  rep(i, n) cin >> h[i] >> s[i];

  auto f = [&](ll arg)
  {
    vector<ll> hist(n + 1, 0);
    rep(i, n)
    {
      if (arg < h[i]) return false;
      ll score = (arg - h[i]) / s[i];
      chmin(score, n);
      hist[score]++;
    }

   ll sum = 0;
    rep(i, n + 1)
    {
      sum += hist[i];
      if (i + 1 < sum) return false; // NG
    }
    return true; // Ok
  };

  ll wa = 0, ac = 1e14 + 1e10;
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