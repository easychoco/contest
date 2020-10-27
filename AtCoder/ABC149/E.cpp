#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i=a;i<(ll)n;++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define Show(val) cout<<(val)<<" "
#define Showln(val) cout<<(val)<<endl

using namespace std;
using ll = long long;
using P = pair<ll, ll>;
// using P = pair<int, int>;
void YN(bool a) { cout << (a ? "Yes" : "No"); }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

void solve()
{
	ll n, m;
	cin >> n >> m;

	vector<ll> a(n);
	rep(i, n) cin >> a[i];
  sort(ALL(a));
  vector<ll> sum_a(a);
  reverse(ALL(sum_a));
  repi(i, 1, n) sum_a[i] += sum_a[i - 1];
  
  auto f = [&](ll arg)
  {
    ll num = 0;
    rep(i, n) num += a.end() - lower_bound(ALL(a), arg - a[i]);
    return num >= m;
  };

  ll ac = a[0] * 2, wa = a.back() * 2 + 1;
  while(wa - ac > 1)
  {
    ll wj = (ac + wa) / 2;
    if ( !f(wj) ) wa = wj;
    else ac = wj;
  }

  ll ans = 0;
  ll num = 0;
  rep(i, n)
  {
    ll ai = a.end() - lower_bound(ALL(a), ac - a[i]);
    num += ai;
    if (ai > 0) ans += sum_a[ai - 1] + a[i] * ai;
  }
  ans -= ac * max(0LL, num - m);
  cout << ans;
}

int main()
{
	fastio;
	solve();

	return 0;
}