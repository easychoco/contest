// https://atcoder.jp/contests/agc035/tasks/agc035_a
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
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  sort(ALL(a));
  if (a.back() == 0)
  {
    YN(true);
    return;
  }

  ll b13 = n / 3;
  ll b23 = 2 * n / 3;

  if (!(a[0] == a[b13 - 1] && a[b13] == a[b23 - 1] && a[b23] == a.back()))
  {
    YN(false);
    return;
  }

  ll a03 = a[0];
  ll a13 = a[b13];
  ll a23 = a[b23];

  if (a03 == 0 && a13 > 0)
  {
    YN(true);
    return;
  }

  if ((a03 ^ a13 ^ a23) == 0)
  {
    YN(true);
    return;
  }

  YN(false);

}

int main()
{
  fastio;
  solve();

  return 0;
}