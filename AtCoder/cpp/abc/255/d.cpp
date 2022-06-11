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

void solve()
{
  ll n, q;
  cin >> n >> q;
  vl a(n);
  rep(i, n)
  {
    cin >> a[i];
  }
  sort(ALL(a));
  ll sum_b = 0;
  ll sum_t = 0;
  vl ab(n);
  vl at(n);
  rep(i, n)
  {
    ab[i] = a[i] - a[0];
    at[i] = a.back() - a[i];
    sum_b += ab[i];
    sum_t += at[i];
  }
  rep(i, n - 1)
  {
    at[i + 1] += at[i];
    ab[i + 1] += ab[i];
  }

  rep(_, q)
  {
    ll x;
    cin >> x;
    ll ans = 0;

    // ll tmp = 0;
    // rep(i, n) tmp += abs(a[i] - x);

    if (a[0] < x && x < a.back())
    {
      // 範囲内
      ll dist = upper_bound(ALL(a), x) - a.begin() - 1;
      ans += at[dist] - (a.back() - x) * (dist + 1);
      ans += (ab[n - 1] - ab[dist]) - (x - a[0]) * (n - dist - 1);

      // print(":", x, dist, a.back() - x, x - a[0]);
      // print(at[dist] - (a.back() - x) * (dist + 1));
      // print(ab[n - 1] - ab[dist], (ab[n - 1] - ab[dist]) - (x - a[0]) * (n - dist - 1));
    }
    else
    {
      // 範囲外
      ans = min(sum_b + abs(a[0] - x) * n, sum_t + abs(a.back() - x) * n);
    }
    print(ans);
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}
