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
void show(){ cout << endl; }
template <class Head, class... Tail>
void show(Head&& head, Tail&&... tail){ cout << head << " "; show(std::forward<Tail>(tail)...); }
void showd(double d){ cout << std::fixed<<setprecision(13) << d << endl; }
template<class T> inline void showall(T& a) { for(auto v:a) cout<<v<<" "; cout<<endl; }
void debug(){ cerr << endl; }
template <class Head, class... Tail>
void debug(Head&& head, Tail&&... tail){ cerr << head << " "; debug(std::forward<Tail>(tail)...); }

void solve()
{
  ll n, k;
  cin >> n >> k;
  vl nega;
  vl posi;
  ll zeros = 0;
  rep(i, n)
  {
    ll a;
    cin >> a;
    if (a == 0) zeros++;
    else if (a < 0) nega.pb(a);
    else posi.pb(a);
  }
  sort(ALL(nega));
  sort(ALL(posi));

  // かけて arg 以下になるものの個数が k 以上である
  auto f = [&](ll arg) -> bool
  {
    ll cnt = 0;
    if (arg >= 0)
    {
      cnt += zeros * (nega.size() + posi.size());
      cnt += zeros * (zeros - 1) / 2;
    }

    // posi * posi
    for (auto itr = posi.begin(); itr != posi.end(); ++itr)
    {
      cnt += upper_bound(itr, posi.end(), arg / *itr) - itr;
      if (*itr * *itr <= arg) cnt--;
    }

    // nega * nega
    for (auto itr = nega.begin(); itr != nega.end(); ++itr)
    {
      cnt += nega.end() - lower_bound(itr, nega.end(), arg / *itr);
      if (*itr * *itr <= arg) cnt--;
    }

    // posi * nega
    for (auto itr = nega.begin(); itr != nega.end(); ++itr)
    {
      cnt += posi.end() - lower_bound(ALL(posi), (-arg - 1) / -*itr + 1);
    }

    return cnt >= k;
  };

  ll wa = -1'001'000'000'000'000'000LL;
  ll ac = 1'001'000'000'000'000'000LL;
  while(ac - wa > 1)
  {
    ll wj = (ac + wa) / 2;
    if ( f(wj) ) ac = wj;
    else wa = wj;
  }
  show(ac);
}

int main()
{
  fastio;
  solve();

  return 0;
}
