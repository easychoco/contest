#include <bits/stdc++.h>
#include <atcoder/all>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i=(a);i<(ll)(n);++i)
#define repe(i,n) repie(i,0,n)
#define repie(i,a,n) for(ll i=(a);i<=(ll)(n);++i)
#define rrep(i,n) rrepi(i,n,0)
#define rrepi(i,n,a) for(ll i=(n);i>=(a);--i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()

using namespace std;
using namespace atcoder;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using P = pair<ll, ll>;
using vp = vector<P>;
using vvp = vector<vp>;
// const ll INF = 1LL << 60;
void YN(bool a) { cout << (a ? "Yes" : "No") << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
void show(){ cout << endl; }
template <class Head, class... Tail>
void show(Head&& head, Tail&&... tail){ cout << head << " "; show(std::forward<Tail>(tail)...); }
template<class T> inline void showall(T& a) { for(auto v:a) cout<<v<<" "; cout<<endl; }

// https://betrue12.hateblo.jp/entry/2020/09/23/005940
using S = long long;
using F = long long;

const S INF = 8e18;

S op(S a, S b){ return std::min(a, b); }
S e(){ return INF; }
S mapping(F f, S x){ return f+x; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }

void solve()
{
  ll n, q;
  string s;
  cin >> n >> q >> s;

  vector<S> v(n);
  ll sum = 0;
  rep(i, n)
  {
    if (s[i] == '(') { sum++; v[i] = sum; }
    if (s[i] == ')') { sum--; v[i] = sum; }
  }
  
  lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);
  rep(_, q)
  {
    ll v, l, r;
    cin >> v >> l >> r;
    l--; r--;
    if (v == 1)
    {
      if (s[l] == s[r]) continue;
      if (s[l] == '(') seg.apply(l, r, -2);
      else seg.apply(l, r, 2);
      swap(s[l], s[r]);
    }
    else
    {
      if (s[l] == ')') { YN(0); continue; }

      F res = seg.prod(l, r + 1) - seg.get(l) + 1;
      if (res < 0) YN(0);
      else {
        YN(seg.get(l) - seg.get(r) == 1);
      }
    }
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}
