// https://atcoder.jp/contests/abc058/tasks/arc071_b
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

using mint = modint1000000007;

void solve()
{
  ll n, m;
  cin >> n >> m;
  vector<ll> x(n);
  vector<ll> y(m);
  rep(i, n) cin >> x[i];
  rep(i, m) cin >> y[i];

  vector<mint> mx(n);
  vector<mint> my(m);
  rep(i, n) mx[i] = x[i] + 1000000007;
  rep(i, m) my[i] = y[i] + 1000000007;

  vector<mint> dx(n - 1), dy(m - 1);
  rep(i, n - 1) { dx[i] = (mx[i + 1] - mx[i]) * mint((n - 1 - i) * (i + 1)); }
  rep(i, m - 1) { dy[i] = (my[i + 1] - my[i]) * mint((m - 1 - i) * (i + 1)); }

  mint xsum = 0;
  mint ysum = 0;
  rep(i, n - 1) xsum += dx[i];
  rep(i, m - 1) ysum += dy[i];

  mint ans = xsum * ysum;
  show(ans.val());
}

int main()
{
  fastio;
  solve();

  return 0;
}
