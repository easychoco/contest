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

void solve()
{
  ll n, k, t, d;
  cin >> n >> k;
  vector<P> sushi(n);
  for(int i = 0; i < n; ++i)
  {
    cin >> t >> d;
    sushi[i] = P(d, t);
  }
  sort(RALL(sushi));

  vector< stack<ll> > now(n + 1, stack<ll>());
  ll sum = 0;
  ll num = 0;

  rep(i, k)
  {
    auto [d, t] = sushi[i];
    sum += d;
    if (now[t].empty()) num++;
    now[t].push(i);
  }

  ll ans = sum + num * num;

  ll ni = k - 1;
  repi(i, k, n)
  {
    auto[sd, st] = sushi[i];
    if (!now[st].empty()) continue;

    // 可能なら ni を除いて i を加えてみる
    while(ni >= 0 && now[sushi[ni].second].size() <= 1) ni--;
    if (ni < 0) break;

    ll idx = now[sushi[ni].second].top();
    now[sushi[ni].second].pop();
    auto [nd, nt] = sushi[idx];
    sum -= nd;
    sum += sd;

    now[st].push(i);
    num++;
    chmax(ans, sum + num * num);
    ni--;
  }
  print(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}