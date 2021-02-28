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


vector<string> mp;
bool seen[2010][2010];
mint memo[2010][2010][3];

mint dfs(int y, int x, int dir)
{
  if (x < 0 || y < 0) return mint(0);
  if (mp[y][x] == '#') return mint(0);
  if (seen[y][x]) return memo[y][x][dir];
  seen[y][x] = true;

  // dir 0:左 1:上 2:左上
  mint le = dfs(y, x-1, 0);
  mint up = dfs(y-1, x, 1);
  mint lu = dfs(y-1, x-1, 2);

  mint sum = le + up + lu;

  memo[y][x][0] = le + sum;
  memo[y][x][1] = up + sum;
  memo[y][x][2] = lu + sum;

  return memo[y][x][dir];
}

void solve()
{
  ll h, w;
  cin >> h >> w;
  mp = vector<string>(h);
  rep(i, h) cin >> mp[i];

  seen[0][0] = true;
  rep(i, 3) memo[0][0][i] = 1;

  mint ans = 0;
  mint a = dfs(h - 1, w - 2, 0);
  mint b = dfs(h - 2, w - 1, 1);
  mint c = dfs(h - 2, w - 2, 2);
  ans = a + b + c;

  cout << ans << endl;
}

int main()
{
  fastio;
  solve();

  return 0;
}