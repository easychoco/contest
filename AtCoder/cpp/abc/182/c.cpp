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
  ll n;
  cin >> n;
  int hist[3] = {0, 0, 0};
  ll cnt = 0;
  while(n > 0)
  {
    hist[(n % 10) % 3]++;
    n /= 10;
    cnt++;
  }
  ll eval = hist[1] + hist[2] * 2;
  ll ans = 0;
  
  if (eval % 3 == 1)
  {
    if (hist[1] > 0) ans = 1;
    else if (hist[2] > 1) ans = 2;
    else ans = -1;
  }
  else if (eval % 3 == 2)
  {
    if (hist[2] > 0) ans = 1;
    else if (hist[1] > 1) ans = 2;
    else ans = 0;
  }

  if (cnt == ans) ans = -1;
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}