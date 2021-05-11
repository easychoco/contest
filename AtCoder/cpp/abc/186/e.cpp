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

tuple<ll, ll, ll> extgcd(ll a, ll b)
{
  if (b == 0) return make_tuple(a, 1LL, 0LL);
  ll g, x, y;
  tie(g, x, y) = extgcd(b, a % b);
  return make_tuple(g, y, x - (a / b) * y);
}

void solve()
{
  ll t;
  cin >> t;
  ll n, s, k;
  rep(ti, t)
  {
    cin >> n >> s >> k;

    // mod n の世界でsにkをans回足して0にする
    // s + k * ans = 0 (mod n)
    // k * ans = -s (mod n)
    // ans = -s / k (mod n)
    // ans = -s * inv(k) (mod n)

    // kx + ny = g
    // kとnをgで割ったとき、xがkの逆元

    // -s = n - s;
    // inv(k) = x
    ll g, x, y;
    tie(g, x, y) = extgcd(k, n);

    if (s % g != 0)
    {
      Showln(-1);
      continue;
    }

    n /= g;
    s /= g;
    ll ans = ((n - s) * x) % n;
    ans += n;
    if (ans >= n) ans -= n;

    Showln(ans);
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}