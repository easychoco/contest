#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i=a;i<(ll)n;++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()

using namespace std;
using ll = long long;
using P = pair<ll, ll>;
void YN(bool a) { cout << (a ? "Yes" : "No") << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
void show(){ cout << endl; }
template <class Head, class... Tail>
void show(Head&& head, Tail&&... tail){ cout << head << " "; show(std::forward<Tail>(tail)...); }
template<class T> inline void showall(T& a) { for(auto v:a) cout<<v<<" "; cout<<endl; }


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

void solve()
{
  ll a, b, c;
  cin >> a >> b >> c;
  /*
  repi(i, 1, 10)
  {
    ll b = i;
    vector<ll> v;
    vector<ll> vmod;
    ll sz = 5;
    rep(bb, sz)
    {
      v.emplace_back(b);
      vmod.emplace_back(b % 10);
      b *= i;
    }
    showall(v);
    showall(vmod);
    show("------");
  }
  */

  a = a % 10;
  if (b > 4) b = b % 4 + 4;
  if (c > 4) c = c % 4 + 4;
  a = powmod(a, pow(b, c), 10);
  show(a);

  /*
  a %= 10;

  ll fa = a;
  ll num = 0;
  while(true)
  {
    fa *= a;
    fa %= 10;
    num++;
    if (fa == a) break;
  }

  ll base = powmod(b, c, num);
  // show(a, num, base);

  ll ans = a;
  rep(i, (base + num - 1) % num) ans = (ans * a) % 10;
  show(ans);
  */
}

int main()
{
  fastio;
  solve();

  return 0;
}