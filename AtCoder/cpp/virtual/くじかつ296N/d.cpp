// https://atcoder.jp/contests/abc178/tasks/abc178_d
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

using mint = modint1000000007;

void solve()
{
  ll s;
  cin >> s;

  // dp[i] = 総和が i にあるような数列の個数
  vector<mint> dp(4010, 1);
  dp[0] = dp[1] = dp[2] = 0;

  repie(i, 6, 2000)
  {
    repie(j, 3, 2000)
    {
      if (i - j < 3) break;
      dp[i] += dp[i - j];
    }
  }
  show(dp[s].val());
}

int main()
{
  fastio;
  solve();

  return 0;
}