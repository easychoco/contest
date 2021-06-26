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
using vvl = vector<vector<ll>>;
using P = pair<ll, ll>;
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
  ll n, q;
  cin >> n >> q;
  vl a(n);
  rep(i, n) cin >> a[i];

  ll sz = n - 1;
  vl e(sz);
  rep (i, sz)
  {
    e[i] = a[i + 1] - a[i];
  }
  ll sum = 0;
  rep(i, sz) sum += abs(e[i]);

  rep(_, q)
  {
    ll l, r, v;
    cin >> l >> r >> v;
    l--; r--;
    
    if (l > 0)
    {
      sum -= abs(e[l - 1]);
      e[l - 1] += v;
      sum += abs(e[l - 1]);
    }
    if (r < sz)
    {
      sum -= abs(e[r]);
      e[r] -= v;
      sum += abs(e[r]);
    }
    show(sum);
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}