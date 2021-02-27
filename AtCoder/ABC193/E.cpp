#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i=a;i<(ll)n;++i)
#define repe(i,n) repie(i,0,n)
#define repie(i,a,n) for(ll i=a;i<=(ll)n;++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()

using namespace std;
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

    ll loop1 = 2*x + 2*y;
    ll loop2 = p + q;
    if (loop1 == loop2)
    {
      if (p < x + y) show(max(x, p));
      else show("infinity");
      continue;
    }

    // 1ループ目で起きている時間は p <= t < q
    // 2ループ目で起きている時間は (p+q) % loop + p <= t < (p+q) % loop + p + q

    ll t1 = x;
    ll t2 = p;

    while(true)
    {
      show(t1, t2);
      if (t2 < t1 + y && t1 < t2 + q)
      {
        show(max(t1, t2));
        break;
      }
      if (loop1 < loop2)
      {
        t2 += loop2;
        t1 += loop1 * (loop2 / loop1);
        while (t1 + loop1 < t2) t1 += loop1;
      }
      else
      {
        t1 += loop1;
        t2 += loop2 * (loop2 / loop1);
        while (t2 + loop2 < t1) t2 += loop2;
      }
      if (t1 > 10000) break;
    }
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}