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
#define pb push_back
#define eb emplace_back

using namespace std;
using namespace atcoder;
using vb = vector<bool>;
using vvb = vector<vb>;
using ll = int_fast64_t;
using vl = vector<ll>;
using vvl = vector<vl>;
using P = pair<ll, ll>;
using vp = vector<P>;
using vvp = vector<vp>;
using T = tuple<ll, ll, ll>;
using vt = vector<T>;
const ll INF = 1LL << 60;
void YN(bool a) { cout << (a ? "Yes" : "No") << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
void show(){ cout << endl; }
template <class Head, class... Tail>
void show(Head&& head, Tail&&... tail){ cout << head << " "; show(std::forward<Tail>(tail)...); }
void showd(double d){ cout << std::fixed<<setprecision(13) << d << endl; }
template<class T> inline void showall(T& a) { for(auto v:a) cout<<v<<" "; cout<<endl; }
void debug(){ cerr << endl; }
template <class Head, class... Tail>
void debug(Head&& head, Tail&&... tail){ cerr << head << " "; debug(std::forward<Tail>(tail)...); }

using mint = modint998244353;

void solve()
{
  ll n, s;
  cin >> n >> s;
  vl a(n);
  rep(i, n) cin >> a[i];

  // 主客転倒で考える
  // 例えば2個の要素の和が S になるとき、そのペアが寄与する量は 2^(n - 2)になる
  // 一般化して、 m 個の和が S になるとき、寄与する量は 2^(n - m) になる
  // サイズが 1 ふえると寄与する量が半分になる
  // だから、すすむほど値が小さくなる dp をする

  // dp[j] = 和が i のものの個数
  vector<mint> dp(3001, 0);
  dp[0] = mint(2).pow(n);

  mint inv2 = mint(2).inv();
  rep(i, n)
  {
    vector< mint > nx(dp);
    repe(j, s - a[i])
    {
      nx[j + a[i]] += dp[j] * inv2;
    }
    dp = nx;
  }

  show(dp[s].val());
}

int main()
{
  fastio;
  solve();

  return 0;
}
