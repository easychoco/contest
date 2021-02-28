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
  ll a, b, c, d;
  cin >> a >> b >> c >> d;

  bool y = false;
  rep(i, 16)
  {
    ll sum1 = 0, sum2 = 0;

    if (i & 1) sum1 += a;
    else sum2 += a;
    if (i & 2) sum1 += b;
    else sum2 += b;
    if (i & 4) sum1 += c;
    else sum2 += c;
    if (i & 8) sum1 += d;
    else sum2 += d;

    if (sum1 == sum2) y = true;
  }
  YN(y);
}

int main()
{
  fastio;
  solve();

  return 0;
}