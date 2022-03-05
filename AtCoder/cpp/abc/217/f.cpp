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

// combination mod prime
// https://www.youtube.com/watch?v=8uowVvQ_-Mo&feature=youtu.be&t=1619
struct combination {
  vector<mint> fact, ifact;
  combination(int n):fact(n+1),ifact(n+1) {
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
    ifact[n] = fact[n].inv();
    for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
  }
  mint operator()(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n]*ifact[k]*ifact[n-k];
  }
} c(1000);

// dp[i][j] = 区間 [i, j] でペアを作る組み合わせ
mint dp[400][400] = { 0 };

void solve()
{
  ll n, m;
  cin >> n >> m;

  vector< vector<bool> > ok(2 * n, vector<bool>(2 * n, false));
  rep(i, m)
  {
    ll a, b;
    cin >> a >> b;
    a--; b--;
    ok[a][b] = true;
  }

  for(int diff = 1; diff < 2 * n; diff += 2) // 区間の幅が小さいものから処理する
  rep(li, 2 * n)
  {
    ll ri = li + diff;
    if (ri >= 2 * n) break;

    // li の ペアが i
    for (int i = li + 1; i <= ri; i += 2)
    {
      if (!ok[li][i]) continue;
      mint le = (li + 1 == i) ? 1 : dp[li + 1][i - 1]; // i の左側
      mint re = (i == ri) ? 1 : dp[i + 1][ri]; // i の右側
      mint comb = c((diff + 1) / 2, (i - li + 1) / 2); // {作るペアの数} C {i までのペアの数}
      dp[li][ri] += le * re * comb;
    }
  }
  show(dp[0][2 * n - 1].val());  
}

int main()
{
  fastio;
  solve();

  return 0;
}
