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
void YN(bool a, string whenT="Yes", string whenF="No") { cout << (a ? whenT : whenF) << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
void print() { cout << endl; }
template <class Head, class... Tail>
void print(Head &&head, Tail &&...tail){ cout << head << " "; print(std::forward<Tail>(tail)...); }
void printd(double d) { cout << std::fixed << setprecision(13) << d << endl; }
template <class T>
inline void printv(T &v){ for (auto a : v) print(a); }
template <class T>
inline void printvp(T &p){ for (auto [a, b] : p) print(a, b); }
template <class T>
inline void printvt(T &t){ for (auto [a, b, c] : t) print(a, b, c); }
void debug() { cerr << endl; }
template <class Head, class... Tail>
void debug(Head&& head, Tail&&... tail){ cerr << head << " "; debug(std::forward<Tail>(tail)...); }

using mint = modint998244353;

void solve()
{
  ll n, l;
  cin >> n >> l;
  vector<string> s(n);
  rep(i, n)
  {
    cin >> s[i];
  }

  // 18 のとき
  // 1 + 2 + ... + 18
  // - 1&2 + 1&3 + ... + 17%18
  // + 
  //
  // pop_count が
  // 奇数の時は +
  // 偶数の時は -
  //

  mint ans = 0;
  repi(mask, 1, 1 << n)
  {
    ll pop_count = 0;
    vl ok(26, 0);
    rep(i, n)
    {
      if (mask >> i & 1)
      {
        pop_count++;
        for (auto c : s[i])
        {
          ll ni = (int)(c - 'a');
          ok[ni]++;
        }
      }
    }
    mint common = 0;
    rep(i, 26)
    {
      common += (ok[i] == pop_count);
    }
    ans += common.pow(l) * ((pop_count & 1) ? 1 : -1);
  }
  print(ans.val());
}

int main()
{
  fastio;
  solve();

  return 0;
}
