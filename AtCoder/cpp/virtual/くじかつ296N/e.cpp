// https://atcoder.jp/contests/abc179/tasks/abc179_d
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
template<class T> inline void showall(T& a) { for(auto v:a) cout<<v.val()<<" "; cout<<endl; }

using mint = modint998244353;

void solve()
{
  ll n, k;
  cin >> n >> k;
  vector<P> ranges(k);
  rep(i, k)
  {
    ll l, r;
    cin >> l >> r;
    ranges[i] = P(l, r);
  }

  vector<mint> dp(2 * n + 3, 0);
  dp[0] = 1;
  mint sum = 0;
  rep(i, n)
  {
    sum += dp[i];
    rep(j, k)
    {
      ll l, r;
      tie(l, r) = ranges[j];
      dp[i + l] += sum;
      dp[i + r + 1] -= sum;
    }
  }
  show(dp[n - 1].val());
}

int main()
{
  fastio;
  solve();

  return 0;
}