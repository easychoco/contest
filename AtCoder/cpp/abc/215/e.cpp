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
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using P = pair<ll, ll>;
const ll INF = 1LL << 60;
void YN(bool a) { cout << (a ? "Yes" : "No") << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
void show(){ cout << endl; }
template <class Head, class... Tail>
void show(Head&& head, Tail&&... tail){ cout << head << " "; show(std::forward<Tail>(tail)...); }
template<class T> inline void showall(T& a) { for(auto v:a) cout<<v<<" "; cout<<endl; }

using mint = modint998244353;

// dp[i][j][k] = i 文字まで見て、j の集合に参加して、最後のコンテストが k である
mint dp[1010][1024][10];

void solve()
{
  ll n;
  string s;
  cin >> n >> s;

  rep(i, n)
  {
    ll now = (ll)(s[i] - 'A');
    rep(mask, 1 << 10)
    {
      rep(last, 10)
      {
        if (last == now) dp[i + 1][mask][last] = dp[i][mask][last] * 2;
        else dp[i + 1][mask][last] = dp[i][mask][last];
      }
    }
    rep(mask, 1 << 10)
    {
      // 集合に now が含まれているとき
      if (mask >> now & 1) continue;

      // 集合に含まれていないので追加する
      rep(last, 10) dp[i + 1][mask | (1 << now)][now] += dp[i][mask][last];
    }
    //  初参加
    dp[i + 1][1 << now][now]++;
  }

  mint ans = 0;
  rep(mask, 1 << 10)
  rep(last, 10)
  {
    ans += dp[n][mask][last];
  }
  show(ans.val());
}

int main()
{
  fastio;
  solve();

  return 0;
}
