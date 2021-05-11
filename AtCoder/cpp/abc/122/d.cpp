#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

// auto mod int
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
const int mod = 1'000'000'007;
struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
  mint operator+(const mint a) const { return mint(*this) += a;}
  mint operator-(const mint a) const { return mint(*this) -= a;}
  mint operator*(const mint a) const { return mint(*this) *= a;}
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const { return pow(mod-2);}
  mint& operator/=(const mint a) { return *this *= a.inv();}
  mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

mint dp[101][4][4][4];
void solve()
{
  int n;
  cin >> n;
  dp[0][3][3][3] = 1;

  for(int len = 0; len <= n; ++len) {
    for(int i1 = 0; i1 < 4; ++i1) {
      for(int i2 = 0; i2 < 4; ++i2) {
        for(int i3 = 0; i3 < 4; ++i3) {
          if (dp[len][i1][i2][i3].x == 0) continue;

          for(int c = 0; c < 4; ++c)
          { // cut
            if (c == 2 && i1 == 1 && i2 == 0) continue; // AGC
            if (c == 1 && i1 == 2 && i2 == 0) continue; // ACG
            if (c == 2 && i1 == 0 && i2 == 1) continue; // GAC
            if (c == 2 && i2 == 1 && i3 == 0) continue; // AG C
            if (c == 2 && i1 == 1 && i3 == 0) continue; // A GC

            dp[len + 1][c][i1][i2] += dp[len][i1][i2][i3];
          }
        }
      }
    }
  }

  mint ans = 0;
  for(int i1 = 0; i1 < 4; ++i1) {
    for(int i2 = 0; i2 < 4; ++i2) {
      for(int i3 = 0; i3 < 4; ++i3) {
        ans += dp[n][i1][i2][i3];
      }
    }
  }
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}