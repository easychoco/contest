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
  ll n, m;
  cin >> n >> m;
  vvp event(m);
  rep(i, n)
  {
    ll a, b;
    cin >> a >> b;
    a--; b--;
    event[a].pb(P(i, 0));
    event[b].pb(P(i, 1));
  }

  ll cnt = 0;
  vl hist(n, 0);
  vl ans(m + 1);
  ll ri = 0;
  while(cnt < n)
  {
    for (auto [idx, ev] : event[ri])
    {
      hist[idx]++;
      if (hist[idx] == 1) cnt++;
    }
    ri++;
  }

  rep(li, m)
  {
    // ri を増やす
    while(ri < m && cnt < n)
    {
      for (auto [idx, ev] : event[ri])
      {
        hist[idx]++;
        if (hist[idx] == 1) cnt++;
      }
      ri++;
    }

    if (cnt == n)
    {
      ans[ri - li - 1]++;
      ans[m - li]--;
    }

    // li を除く
    for (auto [idx, ev] : event[li])
    {
      if (ev == 0) { 
        hist[idx]--;
        if (hist[idx] == 0) cnt--;
      }
      else li = m; // bye
    }
  }

  rep(i, m) ans[i + 1] += ans[i];
  rep(i, m) print(ans[i]);
}

int main()
{
  fastio;
  solve();

  return 0;
}
