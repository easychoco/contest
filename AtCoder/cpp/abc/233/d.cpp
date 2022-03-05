#include <bits/stdc++.h>
#include <atcoder/all>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i=(a);i<(ll)(n);++i)
#define repe(i,n) repie(i,0,n)
#define repie(i,a,n) for(ll i=(a);i<=(ll)(n);++i)
#define rrep(i,n) rrepi(i,n,0)
#define rrepi(i,n,a) for(ll i=(n);i>=(a);--i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()

using namespace std;
using namespace atcoder;
using ll = int_fast64_t;
using vl = vector<ll>;
using vvl = vector<vl>;
using P = pair<ll, ll>;
using vp = vector<P>;
using vvp = vector<vp>;
const ll INF = 1LL << 60;
void YN(bool a) { cout << (a ? "Yes" : "No") << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
void show(){ cout << endl; }
template <class Head, class... Tail>
void show(Head&& head, Tail&&... tail){ cout << head << " "; show(std::forward<Tail>(tail)...); }
template<class T> inline void showall(T& a) { for(auto v:a) cout<<v<<" "; cout<<endl; }

// zero sum range の類題
// 累積和をとって、先頭から見ていく
// それまでに出た数のうち、差が k のものは答えの対象になる
// |k| < 10^15 なので histgram は使えない
// かわりに map を使って、これまで出た数を記録する
void solve()
{
  ll n, k;
  cin >> n >> k;
  vl a(n);
  rep(i, n)
  {
    cin >> a[i];
  }
  vl b(a);
  rep(i, n - 1)
  {
    b[i + 1] += b[i];
  }
  map<ll, ll> mp;
  mp[0] = 1;
  ll ans = 0;
  rep(i, n)
  {
    ans += mp[b[i] - k];
    mp[b[i]]++;
  }
  show(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}
