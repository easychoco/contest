#include <bits/stdc++.h>
 
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
 
using namespace std;
using ll = long long;
 
const double PI = 3.14159265358979;
 
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
  int n, k, a_input;
  cin >> n >> k;
  vector<ll> a_posi;
  vector<ll> a_nega;
  for(int i = 0; i < n; ++i)
  {
    cin >> a_input;
    (a_input < 0 ? a_nega : a_posi).emplace_back(a_input);
  }
 
  if (a_posi.size() == 0 && (k & 1))
  {
    sort(a_nega.begin(), a_nega.end(), greater<ll>());
  }
  else
  {
    sort(a_nega.begin(), a_nega.end());    
    sort(a_posi.begin(), a_posi.end(), greater<ll>());
  }
  if (k == 1)
  {
    mint ans = 0;
    if (a_posi.size()) ans = a_posi[0];
    else ans = a_nega[0];
    cout << ans;
    return;
  }
  if (n == k)
  {
    mint ans = 1;
    for(const auto& a : a_posi) ans *= a;
    for(const auto& a : a_nega) ans *= a;
    cout << ans;
    return;
  }

  int ip = 0, in = 0;
  mint ans = 1;
  for(int i = 0; i < k; i += 2)
  {
    if (k - i == 1)
    {
      if (ip < a_posi.size()) ans *= a_posi[ip];
      else ans *= a_nega[in];
      continue;
    }
 
    ll mp = -1;
    ll mn = -1;
    if (ip + 2 < a_posi.size())
    {
      mp = a_posi[ip] * a_posi[ip + 1];
    }
    else if (ip + 1 < a_posi.size() && ((k & 1) == 0) )
    {
      mp = a_posi[ip] * a_posi[ip + 1];
    }
    if (in + 1 < a_nega.size())
    {
      mn = a_nega[in] * a_nega[in + 1];
    }
 
    if (mp < mn)
    {
      ans *= mn;
      in += 2;
    }
    else if (mn < mp)
    {
      ans *= mp;
      ip += 2;
    }
    else
    {
      ans *= a_posi[ip] * a_posi[ip + 1];
      ip += 2;
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