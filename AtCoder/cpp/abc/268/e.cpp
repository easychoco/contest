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

ll dist(ll a, ll b, ll mod)
{
  if (a > b) swap(a, b);
  // a < b;
  return(min(b - a, a + mod - b));
}

void solve()
{
  ll n;
  cin >> n;
  vl p(n);
  rep(i, n) cin >> p[i];
  vl nums(n);

  rep(i, n) {
    nums[i] = abs(i - p[i]);
    debug(i, p[i], nums[i]);
  }

  sort(ALL(nums));
  printv(nums);

  ll ans = 0;
  if (n & 1) {
    ll mid = nums[n / 2];
    rep(i, n)
    {
      ll pi = (i - mid + n) % n;
      ans += dist(i, p[pi], n);
    }
  }
  else {
    ll mid = nums[n / 2];
    ll score1 = 0;
    rep(i, n)
    {
      ll pi = (i - mid + n) % n;
      score1 += dist(i, p[pi], n);
      debug("mid1 :", mid, "/", dist(i, p[pi], n));
    }

    mid = nums[n / 2 - 1];
    ll score2 = 0;
    rep(i, n)
    {
      ll pi = (i - mid + n) % n;
      score2 += dist(i, p[pi], n);
      debug("mid2 :", mid, "/", dist(i, p[pi], n));
    }
    debug(mid, score1, score2);
    ans = min(score1, score2);
  }
  print(ans);


  {
    rep(mid, n)
    {
      ll s = 0;
      rep(i, n) s += dist(i, p[(i - mid + n) % n], n);
      print(mid, s);      
    }
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}
