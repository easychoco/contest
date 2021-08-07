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

// dp[i][j] = i 番目まで見て j [mg] 消費しているときの最大価値
ll dp[510][200010];
void solve()
{
  ll w, n;
  cin >> w >> n;
  vector<ll> l(n), r(n), v(n);
  rep(i, n)
  {
    cin >> l[i] >> r[i] >> v[i];
  }

  repe(i, n)
  {
    repie(j, l[i], r[i]) chmax(dp[i + 1][j], dp[i][0] + v[i]);
    repe(j, w)
    {
      if (dp[i][j] == 0) continue;
      chmax(dp[i + 1][j + l[i]], dp[i][j] + v[i]);
      chmax(dp[i + 1][j + r[i]], dp[i][j] + v[i]);
      chmax(dp[i + 1][j], dp[i][j]);
    }
  }
  if (dp[n][w] == 0) show(-1);
  else show(dp[n][w]);
}

int main()
{
  fastio;
  solve();

  return 0;
}