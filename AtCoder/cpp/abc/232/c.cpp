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
using ll = int_fast64_t;
using vl = vector<ll>;
using vvl = vector<vl>;
using P = pair<ll, ll>;
using vp = vector<P>;
using vvp = vector<vp>;
const ll INF = 1LL << 60;
void YN(bool a) { cout << (a ? "Yes" : "No") << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
void show(){ cout << endl; }
template <class Head, class... Tail>
void show(Head&& head, Tail&&... tail){ cout << head << " "; show(std::forward<Tail>(tail)...); }
template<class T> inline void showall(T& a) { for(auto v:a) cout<<v<<" "; cout<<endl; }

void solve()
{
  ll n, m;
  cin >> n >> m;
  vp ia(m);
  vp it(m);
  rep(i, m) 
  {
    ll a, b;
    cin >> a >> b;
    a--; b--;
    ia[i] = make_pair(max(a, b), min(a, b));
  }
  rep(i, m) 
  {
    ll c, d;
    cin >> c >> d;
    c--; d--;
    it[i] = make_pair(c, d);
  }

  sort(ALL(ia));

  vl perm = vl(n, 0);
  iota(ALL(perm), (ll)0);
  do {

    vp ii(m);
    rep(i, m)
    {
      auto [c, d] = it[i];
      c = perm[c];
      d = perm[d];
      ii[i] = make_pair(max(c, d), min(c, d));
    }
    sort(ALL(ii));
    if (ia == ii)
    {
      YN(1);
      return;
    }
  } while (next_permutation(ALL(perm)));
  YN(0);
}

int main()
{
  fastio;
  solve();

  return 0;
}
