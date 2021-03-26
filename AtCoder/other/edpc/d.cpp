#include <bits/stdc++.h>
#include <atcoder/all>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i=a;i<(ll)n;++i)
#define repe(i,n) repie(i,0,n)
#define repie(i,a,n) for(ll i=a;i<=(ll)n;++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()

using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<ll, ll>;
void YN(bool a) { cout << (a ? "Yes" : "No") << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
void show(){ cout << endl; }
template <class Head, class... Tail>
void show(Head&& head, Tail&&... tail){ cout << head << " "; show(std::forward<Tail>(tail)...); }
template<class T> inline void showall(T& a) { for(auto v:a) cout<<v<<" "; cout<<endl; }

void solve()
{
  ll n, W;
  cin >> n >> W;
  vector<ll> w(n), v(n);
  rep(i, n) cin >> w[i] >> v[i];

  // dp[i][w] = i まで見て重さが w のときの価値の最大値
  vector< vector<ll> > dp(n + 1, vector<ll>(W * 2 + 10, 0));

  rep(i, n)
  {
    repe(ww, W)
    {
      if (w[i] <= ww) dp[i + 1][ww] = max(dp[i][ww - w[i]] + v[i], dp[i][ww]);
      else dp[i + 1][ww] = dp[i][ww];
    }
  }

  ll ans = 0;
  repe(i, W) chmax(ans, dp[n][i]);
  show(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}