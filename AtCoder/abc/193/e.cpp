#include <bits/stdc++.h>
#include <atcoder/all>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i=a;i<(ll)n;++i)
#define repe(i,n) repie(i,0,n)
#define repie(i,a,n) for(ll i=a;i<=(ll)n;++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()

using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<ll, ll>;
void YN(bool a) { cout << (a ? "Yes" : "No") << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
void show(){ cout << endl; }
template <class Head, class... Tail>
void show(Head&& head, Tail&&... tail){ cout << head << " "; show(std::forward<Tail>(tail)...); }
template<class T> inline void showall(T& a) { for(auto v:a) cout<<v<<" "; cout<<endl; }

void solve()
{
  ll t;
  cin >> t;

  rep(ti, t)
  {
    ll x, y, p, q;
    cin >> x >> y >> p >> q;

    // 1ループ 2x + 2y
    //   A => B => B => A => ...
    // 0 | x    y    x    y

    // % (2X + 2Y) で X <= t < X + Y のときに降りられる

    // 1ループ目で起きている時間は p <= t < q
    // 2ループ目で起きている時間は (p+q) % loop + p <= t < (p+q) % loop + p + q

    ll loop1 = 2*x + 2*y;
    ll loop2 = p + q;

    ll ans = 1LL << 62;
    repi(t1, x, x + y)
    {
      repi(t2, p, p + q)
      {
        auto pp = crt({t1, t2}, {loop1, loop2});
        if (pp != P(0, 0))
        {
          ll num = pp.first;
          if (num == 0) num = pp.second;
          chmin(ans, num);
        }
      }
    }
    if (ans == 1LL<<62) show("infinity");
    else show(ans);
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}