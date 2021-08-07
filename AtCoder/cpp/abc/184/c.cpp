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
  ll r1, r2, c1, c2;
  cin >> r1 >> c1 >> r2 >> c2;
  r2 -= r1;
  c2 -= c1;
  r1 = c1 = 0;

  ll ans = 0;
  if (r1 == r2 && c1 == c2) ans = 0;
  else if (abs(r2) == abs(c2)) ans = 1;
  else if (abs(r2) + abs(c2) <= 3) ans = 1;
  else if (abs(r2) + abs(c2) <= 6) ans = 2;
  else if (abs(r2 - c2) % 2 == 0) ans = 2;
  else if (abs(abs(r2) - abs(c2)) <= 3) ans = 2;
  else ans = 3;

  cout << ans << endl;
}

int main()
{
  fastio;
  solve();

  return 0;
}