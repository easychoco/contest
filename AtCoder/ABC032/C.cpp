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

void solve()
{
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i, n)
  {
    cin >> a[i];
    if (a[i] == 0)
    {
      cout << n << endl;
      return;
    }
  }

  ll ans = 0;
  ll re = 1;
  ll le = 0;
  ll prod = a[0];
  for(le; le < n; ++le)
  {
    while (prod <= k)
    {
      if (re >= n) { re++; break; }
      prod *= a[re];
      re++;
    }
    if (le >= re) break;
    prod /= a[le];
    chmax(ans, re - le - 1LL);
  }
  cout << ans << endl;
}

int main()
{
  fastio;
  solve();

  return 0;
}