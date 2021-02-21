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
void YN(bool a) { cout << (a ? "Yes" : "No") << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
void show(){ cout << endl; }
template <class Head, class... Tail>
void show(Head&& head, Tail&&... tail){ cout << head << " "; show(std::forward<Tail>(tail)...); }
template<class T> inline void showall(T& a) { for(auto v:a) cout<<v<<" "; cout<<endl; }

// dp[i][j][m] = i番目まで見てj個使った時に mod k が m のときの最大値
ll dp[110][110][110];

void solve()
{
  ll n, x;
  cin >> n >> x;
  vector<ll> a(n);
  rep(i, n)
  {
    cin >> a[i];
  }

  ll ans = 1'000000'000000'000000;
  const  ll INF = -1'000000'000000'000000;
  // dp[i][j][m] = i番目まで見てj個使った時に mod k が m のときの最大値
  repi(k, 1, n + 1)
  {
    rep(i1, 110) rep(i2, 110) rep(i3, 110) dp[i1][i2][i3] = INF;

    dp[0][0][0] = 0;
    dp[0][1][a[0] % k] = a[0];
    repi(i, 1, n)
    repi(j, 1, min(i + 2, k + 1))
    {
      rep(m, k)
      {
        chmax( dp[i][j][m], dp[i - 1][j][m] );
      }
      rep(m, k)
      {
        if (dp[i - 1][j - 1][m] >= 0)
        chmax( dp[i][j][(dp[i - 1][j - 1][m] + a[i]) % k], dp[i - 1][j - 1][m] + a[i] );
      }
    }

    if (dp[n - 1][k][x % k] > 0)
    chmin(ans, (x - dp[n - 1][k][x % k]) / k);
  }
  show(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}