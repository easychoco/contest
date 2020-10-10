#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i = a;i < (ll)n;++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define SHOW(str,val) cout<<(str)<<" : "<<(val)<<endl;

using namespace std;
using ll = long long;
using P = pair<ll, ll>;
// using P = pair<int, int>;
void YN(bool a) { cout << (a ? "Yes" : "No"); }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true;} return false;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true;} return false;}

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

void solve()
{
  ll t;
  cin >> t;
  ll in, ia, ib;
  rep(it, t)
  {
    cin >> in >> ia >> ib;

    if (ia < ib) swap(ia, ib);
    // a のほうが大きい

    mint n = in;
    mint a = ia;
    mint b = ib;

    //mint ans = (n-a+1).pow(2)*(n-b+1).pow(2) - (a+2*b-2).pow(2)*(n-a+1).pow(2) + ((n+b-3).pow(2)-(n-b+1).pow(2));
    mint ans = (n-a+1).pow(2)*(n-b+1).pow(2) 
             - (n-a+1).pow(2)*(a+b-1).pow(2)
             + ((n+b-1).pow(2)-(n-b+1).pow(2));
    /*
    ll ans = 1;
    // 4すみ
    (n-b+1).pow(2) - a.pow(2)

    // 左にはいれないときまで
    (a+2*b-2).pow(2)

    // 上にはいれないときまで

    // 上下左右にはいれる
    // (n*n-a*a)*(b*b).inv()*max(0, (n-2*b-a+1).pow(2).x) 通り
    */
    cout << ans << endl;
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}