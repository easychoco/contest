// https://atcoder.jp/contests/abc188/tasks/abc188_e
#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i=a;i<(ll)n;++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()

using namespace std;
using ll = long long;
using P = pair<ll, ll>;
void YN(bool a) { cout << (a ? "Yes" : "No"); }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
void show(){ cout << endl; }
template <class Head, class... Tail>
void show(Head&& head, Tail&&... tail){ cout << head << " "; show(std::forward<Tail>(tail)...); }

void solve()
{
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n);
  vector<P> input(m);
  rep(i, n) cin >> a[i];
  rep(i, m)
  {
    ll x, y;
    cin >> x >> y;
    x--; y--;
    input[i] = P(x, y);
  }

  sort(ALL(input));
  vector<ll> dp(a);
  ll ans = -(1LL << 60);
  rep(i, m)
  {
    ll from, to;
    tie(from, to) = input[i];
    chmax(ans, a[to] - dp[from]);
    dp[to] = min({dp[from], dp[to], a[to]});
  }
  show(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}