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
  ll n, k;
  cin >> n >> k;

  ll ab = max(2LL, k + 1);
  ll cd = ab - k;
  // ab の min は k+2, max は 2n
  // cd の min は 2, max は 2n - k
  ll ans = 0;
  for(ab; max(cd, ab) <= 2 * n; ++ab, ++cd)
  {
    // 足してabになる組み合わせ
    ll score_ab = ab - 1;
    if (ab > n) score_ab -= (ab - n - 1) * 2;

    // 足してcdになる組み合わせ
    ll score_cd = cd - 1;
    if (cd > n) score_cd -= (cd - n - 1) * 2;

    ans += score_ab * score_cd;
  }
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}