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

void solve()
{
  ll n;
  cin >> n;
  vl a(n);
  rep(i, n)
  {
    cin >> a[i];
  }

  // 平均値を arg 以上にすることができるか
  auto f_ave = [&](double arg) -> bool
  {
    vector<double> vec(n, 0.0);
    rep(i, n)
    {
      vec[i] = ((double)a[i] - arg);
    }

    // dp[i] = i 番を選んだ状態で、 i まで見たときの合計の最大値
    vector<double> dp(n, 0.0);
    dp[0] = vec[0];
    dp[1] = vec[1] + max(0.0, vec[0]);
    repi(i, 2, n)
    {
      dp[i] = vec[i] + max(dp[i - 2], dp[i - 1]);
    }

    return max(dp[n - 1], dp[n - 2]) > 0.0;
  };
  double ac = 0, wa = 2'000'000'000;
  while(wa - ac > 0.001)
  {
    double wj = (ac + wa) / 2.0;
    if ( f_ave(wj) ) ac = wj;
    else wa = wj;
  }

  // 中央値を arg 以上にすることができるか
  auto f_med = [&](ll arg) -> bool
  {
    vl vec(n, 0);
    rep(i, n)
    {
      vec[i] = (a[i] - arg);
    }

    // dp[i] = i 番を選んだ状態で、arg 以上の数の個数の最大値
    vl dp(n, 0);
    dp[0] = vec[0] >= 0 ? 1 : -1;
    dp[1] = (vec[1] >= 0 ? 1 : -1) + max((ll)0, dp[0]);
    repi(i, 2, n)
    {
      dp[i] = (vec[i] >= 0 ? 1 : -1) + max(dp[i - 2], dp[i - 1]);
    }

    return max(dp[n - 1], dp[n - 2]) >= 1;
  };
  ll le = 0, re = 1'000'000'001LL;
  while(re - le > 1)
  {
    ll wj = (le + re) / 2;
    if ( f_med(wj) ) le = wj;
    else re = wj;
  }

  show(ac);
  show(le);
}

int main()
{
  fastio;
  solve();

  return 0;
}
