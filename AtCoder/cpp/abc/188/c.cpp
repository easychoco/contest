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
  P la = P(0, 0), ra = P(0, 0);
  rep(i, 1<<(n-1))
  {
    ll a;
    cin >> a;
    P ta = P(a, i + 1);
    chmax(la, ta);
  }
  rep(i, 1<<(n-1))
  {
    ll a;
    cin >> a;
    P ta = P(a, i + (1<<(n-1)) + 1);
    chmax(ra, ta);
  }

  chmin(la, ra);
  Show(la.second);
}

int main()
{
  fastio;
  solve();

  return 0;
}