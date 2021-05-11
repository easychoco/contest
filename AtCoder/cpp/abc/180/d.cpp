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
  ll xi, yi, ai, bi;
  cin >> xi >> yi >> ai >> bi;

  __uint128_t y = yi, a = ai, b = bi;
  __uint128_t x = xi;
  ll exp = 0;

  // a : + tuyo * (a - 1)
  // b : + b

  while(x * a < y && x * a < x + b)
  {
    x *= a;
    exp++;
  }
  if (x < y)
  {
    exp += (y - x - 1) / b;
  }

  cout << exp;
}

int main()
{
  fastio;
  solve();

  return 0;
}