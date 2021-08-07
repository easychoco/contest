#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i = a;i < (ll)n;++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define SHOW(str,val) cout<<(str)<<" : "<<(val)<<endl;

using namespace std;
using ll = long long;
using P = pair<ll, ll>;
// using P = pair<int, int>;
void YN(bool a) { cout << (a ? "Yes" : "No"); }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true;} return false;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true;} return false;}

void solve()
{
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  repi(i, 1, n) a[i] += a[i - 1];

  ll ans = 1LL << 60;
  bool plus = true;
  rep(loop_cnt, 2)
  {
    ll tmp = 0;
    ll dif = 0;
    rep(i, n)
    {
      ll d = 0;
      if      ( plus && a[i] + dif <= 0) d =  1 - a[i] - dif;
      else if (!plus && a[i] + dif >= 0) d = -1 - a[i] - dif;
      tmp += abs(d);
      dif += d;
      plus = !plus;
    }
    chmin(ans, tmp);
    plus = false;
  }
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}