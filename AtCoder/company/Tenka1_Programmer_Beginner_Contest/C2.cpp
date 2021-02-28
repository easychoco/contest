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
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  ll ans = 0;
  sort(ALL(a));
  auto bi = a.begin();
  auto ri = a.end();
  bi++;
  ri--;
  ll front = a[0];
  ll back = a[0];
  while(bi <= ri)
  {
    ll m1 = abs(*bi - front);
    ll m2 = abs(*bi - back);
    ll m3 = abs(*ri - front);
    ll m4 = abs(*ri - back);
    ll mm = max({m1, m2, m3, m4});
    ans += mm;
    if (mm == m1)
    {
      front = *bi;
      bi++;
    }
    else if (mm == m2)
    {
      back = *bi;
      bi++;
    }
    else if (mm == m3)
    {
      front = *ri;
      ri--;
    }
    else
    {
      back = *ri;
      ri--; 
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