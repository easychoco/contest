// https://atcoder.jp/contests/code-festival-2016-qualc/tasks/codefestival_2016_qualC_c
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
  ll n;
  cin >> n;
  vector<ll> t(n), a(n);
  rep(i, n) cin >> t[i];
  rep(i, n) cin >> a[i];

  ll max_height = 0;
  rep(i, n)
  {
    if (a[i] == t[i]) max_height = a[i];
  }

  bool ok = (a[0] == t.back());
  ok &= (max_height == t.back());
  ok &= (max_height == a[0]);

  if (!ok)
  {
    cout << "0\n";
    return;
  }

  vector<mint> perm(n, 0);
  perm[0] = 1;
  perm.back() = 1;

  for(int i = 1; i < n - 1; ++i)
  {
    if (t[i - 1] < t[i]) perm[i] = 1;
    else if(a[i] > a[i + 1]) perm[i] = 1;
    else perm[i] = min(a[i], t[i]);
  }
  mint ans = 1;
  rep(i, n) ans *= perm[i];
  cout << ans << endl;
}

int main()
{
  fastio;
  solve();

  return 0;
}