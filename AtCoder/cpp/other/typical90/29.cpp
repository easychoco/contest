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

using S = ll;
using F = ll;
const F ID = 1LL << 60;
S op(S l, S r) { return max(l, r); }
S e() { return 0; }
S mapping(F f, S x) { return (f == ID ? x : f); }
S composition(F f, F g) { return (f == ID ? g : f); }
F id() { return ID; }

void solve()
{
  ll w, n;
  cin >> w >> n;

  lazy_segtree<ll, op, e, ll, mapping, composition, id> seg(w + 10);
 
  rep(i, n)
  {
    ll l, r;
    cin >> l >> r;
    ll ans = seg.prod(l, r + 1) + 1;
    seg.apply(l, r + 1, ans);
    show(ans);
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}