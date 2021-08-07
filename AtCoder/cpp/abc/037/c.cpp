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
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  ll ans = 0;
  rep(i, n) ans += a[i] * k;
  rep(i, k)
  {
    ans -= a[i] * (k - i - 1);
    ans -= a[n - i - 1] * (k - i - 1);
  }
  cout << ans << endl;
}

int main()
{
  fastio;
  solve();

  return 0;
}