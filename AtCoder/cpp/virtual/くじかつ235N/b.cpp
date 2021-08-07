// https://atcoder.jp/contests/abc127/tasks/abc127_c
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
  ll n, m;
  cin >> n >> m;

  ll l, r;
  vector<ll> hist(n + 1, 0);
  rep(i, n)
  {
    cin >> l >> r;
    hist[l - 1]++;
    hist[r]--;
  }

  rep(i, n) hist[i + 1] += hist[i];
  ll ans = 0;
  rep(i, n) ans += hist[i] == n;
  Showln(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}