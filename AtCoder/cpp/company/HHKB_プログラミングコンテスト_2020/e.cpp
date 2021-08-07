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
  ll h, w;
  cin >> h >> w;
  vector<string> s(h);
  vector< vector<ll> > mp(h, vector<ll>(w, 0));
  for(int i = 0; i < h; ++i)
  {
    cin >> s[i];
  }

  ll n = 0;

  // 横
  rep(y, h) rep(x, w)
  {
    if (s[y][x] == '#') continue;
    ll px = x;
    while(px < w && s[y][px] == '.') px++;
    repi(xx, x, px) mp[y][xx] = px - x;
    n += px - x;
    x = px;
  }

  // 縦
  rep(x, w) rep(y, h)
  {
    if (s[y][x] == '#') continue;
    ll py = y;
    while(py < h && s[py][x] == '.') py++;
    repi(yy, y, py) mp[yy][x] += py - y - 1;
    y = py;
  }

  mint ans = 0;
  mint two = 2;
  mint all = two.pow(n);
  rep(y, h) rep(x, w)
  {
    if (mp[y][x] == 0) continue;
    ans += all - two.pow(n - mp[y][x]);
  }
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}