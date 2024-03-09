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


P op(P a, P b) { 
  if (a.first > b.first) return a;
  if (a.first < b.first) return b;
  return a.second < b.second ? a : b;
}
P e() { return P(0, INF); }

void solve()
{
  ll n, k;
  cin >> n >> k;
  vl a(n);
  rep(i, n) cin >> a[i];

  vl sz(k);
  rep(i, k) {
    sz[i] = n / k + (n % k > 0 ? n % k > i : 0);
  }

  vector<segtree<P, op, e>> segs;
  for (const auto& s : sz) {
    segs.push_back(segtree<P, op, e>(s + 1));
  }

  rep(i, n) {
    ll idx = i % k;
    segs[idx].set(i / k, P(a[i], i));
  }

  ll loop = 0;
  ll now_idx = 0;
  vl ans;
  while(now_idx < n) {
    ll seg_idx = loop % k;
    P now = segs[seg_idx].prod(now_idx / k, sz[seg_idx]);
    now_idx = now.second + 1;
    ans.pb(now.first);
    loop++;
  }
  printv(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}
