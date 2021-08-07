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
  ll n;
  cin >> n;
  vector<P> range(n);
  rep(i, n)
  {
    ll t, l, r;
    cin >> t >> l >> r;
    if (t == 1) range[i] = make_pair(l * 2, r * 2);
    if (t == 2) range[i] = make_pair(l * 2, r * 2 - 1);
    if (t == 3) range[i] = make_pair(l * 2 + 1, r * 2);
    if (t == 4) range[i] = make_pair(l * 2 + 1, r * 2 - 1);
  }

  ll ans = 0;

  rep(i1, n)
  rep(i2, i1)
  {
    ll l1, r1, l2, r2;
    tie(l1, r1) = range[i1];
    tie(l2, r2) = range[i2];
    if (l2 <= r1 && l1 <= r2) ans++;
    else if (l1 <= r2 && l2 <= r1) ans++;
  }
  show(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}