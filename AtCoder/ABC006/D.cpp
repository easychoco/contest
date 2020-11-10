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
  ll n;
  cin >> n;
  vector<ll> c(n);
  rep(i, n) cin >> c[i];

  // dp[i] : LISの長さがiの時の末尾の最小値
  const int INF = 1LL << 30;
  vector<ll> dp(n + 1, INF);

  dp[0] = c[0];
  rep(i, n)
  {
    auto itr = lower_bound(ALL(dp), c[i]);
    *itr = c[i];
  }

  cout << n - distance(dp.begin(), lower_bound(ALL(dp), INF)) << endl;
}

int main()
{
  fastio;
  solve();

  return 0;
}