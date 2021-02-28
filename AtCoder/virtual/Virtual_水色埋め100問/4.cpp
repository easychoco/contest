// https://atcoder.jp/contests/abc123/tasks/abc123_d
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
  ll x, y, z, k;
  cin >> x >> y >> z >> k;
  vector<ll> a(x), b(y), c(z);
  rep(i, x) cin >> a[i];
  rep(i, y) cin >> b[i];
  rep(i, z) cin >> c[i];

  vector<ll> sum_xy;
  rep(i, x) rep(j, y) sum_xy.emplace_back(a[i] + b[j]);
  sort(RALL(sum_xy));

  vector<ll> sum;
  rep(i, min(1000LL, x*y)) rep(j, z)sum.emplace_back(sum_xy[i] + c[j]);
  sort(RALL(sum));

  rep(i, k) Showln(sum[i]);
}

int main()
{
  fastio;
  solve();

  return 0;
}