// https://atcoder.jp/contests/abc105/tasks/abc105_d
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
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  vector<ll> b(a);
  rep(i, n - 1) b[i + 1] += b[i];

  map<ll, ll> hist;
  rep(i, n) hist[b[i] % m]++;

  ll ans = hist[0];
  for(const auto& h : hist)
  {
    ll num = h.second;
    ans += num * (num - 1) / 2;
  }

  cout << ans << endl;
}

int main()
{
  fastio;
  solve();

  return 0;
}