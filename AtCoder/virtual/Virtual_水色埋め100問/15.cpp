// https://atcoder.jp/contests/abc122/tasks/abc122_d
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

  
// auto mod int
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
const int mod = 1000000007;
// const int mod = 998244353;
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

// dp[i][i1][i2][i3] = i文字まで見た時、後ろ3文字がi1,i2,i3になっている文字列の個数
mint dp[100][4][4][4];

void solve()
{
  ll n;
  cin >> n;

  // 0 : A
  // 1 : G
  // 2 : C
  // 3 : T

  rep(i1, 4)
  rep(i2, 4)
  rep(i3, 4)
  {
    dp[2][i1][i2][i3] = 1;
  }
  dp[2][0][1][2] = 0;
  dp[2][0][2][1] = 0;
  dp[2][1][0][2] = 0;

  repi(i0, 3, n)
  {
    rep(i1, 4)
    rep(i2, 4)
    rep(i3, 4)
    {
      if (i1 == 0 && i2 == 1 && i3 == 2) continue;
      if (i1 == 0 && i2 == 2 && i3 == 1) continue;
      if (i1 == 1 && i2 == 0 && i3 == 2) continue;

      // A
      int now = 0;
      dp[i0][i2][i3][now] += dp[i0 - 1][i1][i2][i3];

      // G
      now = 1;
      if (!(i2 == 0 && i3 == 2)) dp[i0][i2][i3][now] += dp[i0 - 1][i1][i2][i3];

      // C
      now = 2;
      if (!(i2 == 0 && i3 == 1) &&
          !(i2 == 1 && i3 == 0) &&
          !(i1 == 0 && i3 == 1) &&
          !(i1 == 0 && i2 == 1)
      )
      {
        dp[i0][i2][i3][now] += dp[i0 - 1][i1][i2][i3];
      }

      // T
      now = 3;
      dp[i0][i2][i3][now] += dp[i0 - 1][i1][i2][i3];
    }
  }
  mint ans = 0;
  rep(i1, 4)
  rep(i2, 4)
  rep(i3, 4)
  {
    ans += dp[n - 1][i1][i2][i3];
  }
  cout << ans << endl;
}

int main()
{
  fastio;
  solve();

  return 0;
}