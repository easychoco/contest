// https://atcoder.jp/contests/abc180/tasks/abc180_e
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

  vector<tuple<ll, ll, ll>> city(n);
  rep(i, n) 
  {
    ll x, y, z;
    cin >> x >> y >> z;
    city[i] = make_tuple(x, y, z);
  }

  auto dist = [&](int from, int to)
  {
    ll x1, y1, z1, x2, y2, z2;
    tie(x1, y1, z1) = city[from];
    tie(x2, y2, z2) = city[to];
    return abs(x1 - x2) + abs(y1 - y2) + max(0LL, z1 - z2);
  };

  // tsp
  // traveling salesman
  // 巡回セールスマン問題
  const ll INF = 1LL << 60;
  // dp[i][j] = いまjにいて、i(mask)の街に訪れているときのコストの最小値
  vector< vector<ll> > dp(1<<n, vector<ll>(n, INF));

  // 開始地点は0固定
  repi(i, 1, n) dp[1<<i][i] = dist(0, i);

  // 全地点開始なら
  // rep(i, n) dp[1 << i][i] = 1;

  rep(mask, 1<<n) rep(now, n)
  {
    if (1 << now & mask) rep(next, n)
    {
      if (1 << next & mask) continue;
      chmin(dp[mask | (1<<next)][next], dp[mask][now] + dist(now, next));
    }
  }
  show(dp[(1 << n) - 1][0]);
}

int main()
{
  fastio;
  solve();

  return 0;
}