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
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  ll ans = 1LL << 60;
  rep(bit, 1LL<<n)
  {
    ll xx = 0;
    ll oo = a[0];
    repi(i, 1, n)
    {
      bool n1 = (bit & (1 << i)) > 0;
      bool p1 = (bit & (1 << (i-1))) > 0;
      if (n1 != p1)
      {
        xx ^= oo;
        oo = 0;
      }
      oo |= a[i];
    }
    xx ^= oo;
    chmin(ans, xx);
  }
  show(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}