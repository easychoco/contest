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
  ll n;
  cin >> n;
  vector<ll> t(n);
  rep(i, n)
  {
    cin >> t[i];
  }

  ll sum = accumulate(ALL(t), 0LL);

  // dp[i][j] = i 番目まで見て 重さが j 以下を作れるか
  vector< vector<bool> > dp(n + 1, vector<bool>(sum + 1, false));
  dp[0][0] = true;
  rep(i, n) repe(j, sum)
  {
    if (j >= t[i] && dp[i][j - t[i]]) dp[i + 1][j] = true;
    else dp[i + 1][j] = dp[i][j];
  }

  repie(j, sum / 2, sum)
  {
    if (dp[n][j] && sum - j <= j)
    {
      show(j);
      return;
    }
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}