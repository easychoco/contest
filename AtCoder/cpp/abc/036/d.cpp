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

vector< vector<ll> > G;
mint num[2][100010];
bool seen[2][100010];

mint dfs(ll parent, ll n, int b)
{
  if (seen[b][n]) return num[b][n];
  seen[b][n] = true;

  mint ret = 1;
  if (b)
  {
    for(const auto& v : G[n])
    {
      if (v == parent) continue;
      ret *= dfs(n, v, 0);
    }
  }
  else
  {
    for(const auto& v : G[n])
    {
      mint ret_v = 0;
      if (v == parent)
      {
        if (G[n].size() == 1) return num[b][n] = 1;
        continue;
      }
      ret_v += dfs(n, v, 0);
      ret_v += dfs(n, v, 1);
      ret *= ret_v;
    }
  }
  return num[b][n] = ret;
}

void solve()
{
  ll n, a, b;
  cin >> n;
  G = vector< vector<ll> >(n, vector<ll>());
  rep(i, n - 1)
  {
    cin >> a >> b;
    --a; --b;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }
  mint ans = dfs(-1, 0, 0) + dfs(-1, 0, 1);
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}