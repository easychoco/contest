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
  vector<ll> ha(46, 0), hb(46, 0), hc(46, 0);
  
  rep(i, n) { ll a; cin >> a; ha[a % 46]++; }
  rep(i, n) { ll b; cin >> b; hb[b % 46]++; }
  rep(i, n) { ll c; cin >> c; hc[c % 46]++; }

  ll ans = 0;
  rep(a, 46)
  {
    if (ha[a] == 0) continue;
    rep(b, 46)
    {
      if (hb[b] == 0) continue;
      ll c = (92 - a - b) % 46;
      ans += ha[a] * hb[b] * hc[c];
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