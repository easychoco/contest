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
  const ll mod = 998244353;
  ll a, b, c;
  cin >> a >> b >> c;
  a = a * (a + 1) / 2;
  b = b * (b + 1) / 2;
  c = c * (c + 1) / 2;
  a %= mod;
  b %= mod;
  c %= mod;

  ll ans = a * b % mod;
  ans = ans * c % mod;
  cout << ans;



}

int main()
{
  fastio;
  solve();

  return 0;
}