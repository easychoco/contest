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

// a^n % mod を計算する O(log n)
ll powmod(ll a, ll n, ll mod) {
  ll ret = 1;
  while (n > 0) {
    if (n % 2 == 1) { ret = ret * a % mod; }
    a = a * a % mod;
    n /= 2;
  }
  return ret;
}

// nCr % mod を計算する O(r)
ll combmod(ll n, ll r, ll mod) {
  ll x = 1, y = 1;
  r = min(n - r, r);
  for(ll i = 0; i < r; ++i) { x = x * (n - i) % mod; }	// 分子
  for(ll i = 1; i <= r; ++i) { y = y * i % mod; }			// 分母
  return x * powmod(y, mod - 2, mod) % mod;	// nCr = (分子) * (分母)^-1 mod M
}

void solve()
{
  ll w, h;
  cin >> w >> h;
  cout << combmod(w + h - 2, h - 1, 1000000007LL) << endl;
}

int main()
{
  fastio;
  solve();

  return 0;
}