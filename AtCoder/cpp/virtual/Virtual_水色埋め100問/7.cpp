// https://atcoder.jp/contests/abc100/tasks/abc100_d
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
  vector<ll> x(n), y(n), z(n);
  rep(i, n) cin >> x[i] >> y[i] >> z[i];

  ll ans = -1001001001001001;
  rep(mask, 8)
  {
    int s1 = (mask & 1) ? 1 : -1;
    int s2 = (mask & 2) ? 1 : -1;
    int s3 = (mask & 4) ? 1 : -1;
    vector<ll> sum;
    rep(i, n) sum.emplace_back(x[i] * s1 + y[i] * s2 + z[i] * s3);
    sort(RALL(sum));
    chmax(ans, accumulate(sum.begin(), next(sum.begin(), m), 0LL));
  }
  cout << ans << endl;
}

int main()
{
  fastio;
  solve();

  return 0;
}