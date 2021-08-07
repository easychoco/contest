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

void solve()
{
  long double x, y, r;
  cin >> x >> y >> r;
  r = nextafter(r, 1LL << 60);
  ll ans = 0;
  for(ll xi = ceil(x - r); xi <= floor(x + r); ++xi)
  {
    long double yi = sqrt(r*r - (xi - x)*(xi - x));
    ll up = floor(y + yi);
    ll down = ceil(y - yi);
    ans += up - down + 1;
  }
  Showln(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}