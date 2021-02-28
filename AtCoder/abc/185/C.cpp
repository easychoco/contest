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

// nCr % mod を計算する O(r)
__int128 combmod(__int128 n, __int128 r) {
  __int128 x = 1, y = 1;
  r = min(n - r, r);
  for(ll i = 0; i < r; ++i) { x = x * (n - i); }	// 分子
  for(ll i = 1; i <= r; ++i) { y = y * i; }			// 分母
  return x / y;	// nCr = (分子) * (分母)^-1 mod M
}

void solve()
{
  ll l;
  cin >> l;

  __int128 n = l - 1;
  __int128 r = 11;
  ll ans = combmod(l - 1, 11);
  cout << ans << endl;
}

int main()
{
  fastio;
  solve();

  return 0;
}