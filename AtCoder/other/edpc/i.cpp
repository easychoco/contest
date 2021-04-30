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
  vector<double> p(n);
  rep(i, n)
  {
    cin >> p[i];
    /*
    string in;
    cin >> in;
    p[i] = stoll(in.substr(2));
    */
  }

  // dp[i][j] = 初めの i 枚のコインを投げたときに、表が j 枚となる確率
  vector< vector<double> > dp(3010, vector<double>(3010, 0.0));
  dp[0][0] = 1.0;

  rep(i, n) repie(j, 0, i)
  {
    // 表
    dp[i + 1][j + 1] += dp[i][j] * p[i];

    // 裏
    dp[i + 1][j] += dp[i][j] * (1.0 - p[i]);
  }

  double ans = 0.0;
  repie(i, n / 2 + 1, n) ans += dp[n][i];
  printf("%.9lf", ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}