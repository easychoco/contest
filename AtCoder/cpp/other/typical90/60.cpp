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
  vl a(n);
  rep(i, n) cin >> a[i];

  ll ans = 0;
  vl dp_asc(n, INF);
  vl dp_rev(n, INF);

  vl len_asc(n, 0);
  vl len_rev(n, 0);
  rep(i, n)
  {
    // 左から
    auto idx = upper_bound(ALL(dp_asc), a[i]) - dp_asc.begin();
    if (idx == 0) dp_asc[idx] = a[i];
    else if (dp_asc[idx - 1] != a[i]) dp_asc[idx] = a[i];

    // 右から
    ll ri = n - i - 1;
    auto idx_rev = upper_bound(ALL(dp_rev), a[ri]) - dp_rev.begin();
    if (idx_rev == 0) dp_rev[idx_rev] = a[ri];
    else if (dp_rev[idx_rev - 1] != a[ri]) dp_rev[idx_rev] = a[ri];

    // 最長部分列を求める
    len_asc[i] = lower_bound(ALL(dp_asc), INF) - dp_asc.begin();
    len_rev[i] = lower_bound(ALL(dp_rev), INF) - dp_rev.begin();
  }
  rep(i, n) chmax(ans, len_asc[i] + len_rev[n - i - 1] - 1);
  show(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}