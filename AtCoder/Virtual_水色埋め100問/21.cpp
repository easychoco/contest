// https://atcoder.jp/contests/abc128/tasks/abc128_d
#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i=a;i<(ll)n;++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define Show(val) cout<<(val)<<" "
#define Showln(val) cout<<(val)<<endl

using namespace std;
using ll = long long;
using P = pair<ll, ll>;
// using P = pair<int, int>;
void YN(bool a) { cout << (a ? "Yes" : "No"); }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

void solve()
{
  ll n, k;
  cin >> n >> k;
  vector<ll> v(n);
  rep(i, n) cin >> v[i];

  // とれるだけとって、戻せるだけ戻す
  // とる全通りはn^2
  // O(n^2 * n log n)
  ll ans = 0;

  // i個とる、k-i個戻す
  for(int i = 1; i <= min(n, k); ++i)
  {
    // 左からl個、右からr個とる
    for(int l = 0; l <= i; ++l)
    {
      int r = i - l;

      vector<ll> deq;
      rep(li, l) deq.emplace_back(v[li]);
      rep(ri, r) deq.emplace_back(v[n - ri - 1]);

      sort(ALL(deq));
      ll sum = accumulate(ALL(deq), 0LL);
      rep(di, k-i)
      {
        if (deq[di] < 0) sum -= deq[di];
        else break;
      }
      chmax(ans, sum);
    }
  }

  cout << ans << endl;
}

int main()
{
  fastio;
  solve();

  return 0;
}