#include <bits/stdc++.h>
#include <atcoder/all>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i=(a);i<(ll)(n);++i)
#define repe(i,n) repie(i,0,n)
#define repie(i,a,n) for(ll i=(a);i<=(ll)(n);++i)
#define rrep(i,n) rrepi(i,n,0)
#define rrepi(i,n,a) for(ll i=(n);i>=(ll)(a);--i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define pb push_back
#define eb emplace_back

using namespace std;
using namespace atcoder;
using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vs = vector<string>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vvvl = vector<vvl>;
using P = pair<ll, ll>;
using vp = vector<P>;
using vvp = vector<vp>;
using T = tuple<ll, ll, ll>;
using vt = vector<T>;
const ll INF = 1LL << 60;
void YN(bool a, string whenT="Yes", string whenF="No") { cout << (a ? whenT : whenF) << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
void print() { cout << endl; }
template <class T>
void print(T &&t){ cout << t << endl; }
template <class Head, class... Tail>
void print(Head &&head, Tail &&...tail){ cout << head << " "; print(std::forward<Tail>(tail)...); }
void printd(double d) { cout << std::fixed << setprecision(13) << d << endl; }
template <class T>
inline void printv(T &v){ for (auto a : v) print(a); }
template <class T>
inline void printp(T &p){ for (auto [a, b] : p) print(a, b); }
template <class T>
inline void printt(T &t){ for (auto [a, b, c] : t) print(a, b, c); }
void debug() { cerr << endl; }
template <class Head, class... Tail>
void debug(Head&& head, Tail&&... tail){ cerr << head << " "; debug(std::forward<Tail>(tail)...); }

using mint = modint998244353;

using vm = vector<mint>;
using vvm = vector<vm>;
using vvvm = vector<vvm>;

void solve()
{
  ll n, m, a, b, c, d, e, f;
  cin >> n >> m >> a >> b >> c >> d >> e >> f;
  set<P> st;
  rep(i, m)
  {
    ll x, y;
    cin >> x >> y;
    st.insert(P(x, y));
  }

  // dp[i][j][k] =
  // i 回動いて
  // ワープ1 を j 回
  // ワープ1 を k 回
  // の時の組み合わせ
  vvvm dp(n + 10, vvm(n + 10, vm(n + 10, 0)));
  dp[0][0][0] = 1;

  repe(all, n)
  {
    repe(i1, all)
    {
      repe(i2, all)
      {
        ll i3 = all - i1 - i2;
        if (i3 < 0) break;

        ll tx = a * i1 + c * i2 + e * i3;
        ll ty = b * i1 + d * i2 + f * i3;
        if (st.find(P(tx, ty)) != st.end())
        {
          dp[all][i1][i2] = 0;
          continue;
        }

        dp[all + 1][i1 + 1][i2] += dp[all][i1][i2];
        dp[all + 1][i1][i2 + 1] += dp[all][i1][i2];
        dp[all + 1][i1][i2] += dp[all][i1][i2];
      }
    }
  }

  mint ans = 0;
  repe(i1, n)
  repe(i2, n)
  {
    ans += dp[n][i1][i2];
  }
  print(ans.val());
}

int main()
{
  fastio;
  solve();

  return 0;
}
