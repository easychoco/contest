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
  ll n, ta, tb, tc;
  cin >> n >> ta >> tb >> tc;
  ll a = max({ta, tb, tc});
  ll c = min({ta, tb, tc});
  ll b = ta + tb + tc - a - c;

  // a > b > c になっている
  ll ans = 1LL << 60;
  for (ll na = n / a; na >= 0; --na)
  {
    for (ll nb = (n - (na * a)) / b; nb >= 0; --nb)
    {
      if (na + nb >= 10000) break;
      if ((n - (na * a) - (nb * b)) % c == 0) chmin(ans, na + nb + (n - (na * a) - (nb * b)) / c);
    }
  }
  show(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}