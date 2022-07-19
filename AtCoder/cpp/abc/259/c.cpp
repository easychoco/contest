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

/**
 * @brief
 * ランレングス圧縮 runlength encoding
 * O(|S|)
 * 
 * @param s ランレングス圧縮をする文字列
 * @return vector< pair<文字, 個数> > を返す
 */
vector<pair<char, ll>> run_length_encoding(const string s) {
  vector<pair<char, ll>> runlength { make_pair(s[0], 1) };
  repi (i, 1, s.length()) {
    const char now = s[i];
    if (runlength.back().first == now) runlength.back().second++;
    else runlength.pb(make_pair(now, 1));
  }
  return runlength;
}

void solve()
{
  string s, t;
  cin >> s >> t;
  auto ps = run_length_encoding(s);
  auto pt = run_length_encoding(t);
  if (ps.size() != pt.size()) YN(false);
  else
  {
    bool ok = true;
    rep(i, ps.size())
    {
      auto [sc, sn] = ps[i];
      auto [tc, tn] = pt[i];
      if (sc != tc) ok = false;
      if (sn == 1 && tn > 1) ok = false;
      if (sn > tn) ok = false;
    }
    YN(ok);
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}
