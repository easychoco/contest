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

using namespace std;
using namespace atcoder;
using ll = int_fast64_t;
using vl = vector<ll>;
using vvl = vector<vl>;
using P = pair<ll, ll>;
using vp = vector<P>;
using vvp = vector<vp>;
const ll INF = 1LL << 60;
void YN(bool a) { cout << (a ? "Yes" : "No") << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
void show(){ cout << endl; }
template <class Head, class... Tail>
void show(Head&& head, Tail&&... tail){ cout << head << " "; show(std::forward<Tail>(tail)...); }
template<class T> inline void showall(T& a) { for(auto v:a) cout<<v<<" "; cout<<endl; }

void solve()
{
  ll n;
  cin >> n;
  vl a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];

  // 左側が arg の長さの時にかかる時間よりも右側の時間のほうが長い
  auto f = [&](double arg) -> bool
  {
    double total = 0; // 左側の長さ
    double ls = 0.0; // 左側の長さが arg の時にかかる時間
    double rs = 0.0; // 右側の長さが arg の時にかかる時間
    rep(i, n)
    {
      double ra = (double)a[i];
      double rb = (double)b[i];
      if (total + ra < arg)
      {
        total += ra;
        ls += ra / rb;
      }
      else
      {
        double res = arg - total;
        ls += res / rb;
        rs += (ra - res) / rb;

        repi(j, i + 1, n) rs += (double)a[j] / (double)b[j];
        break;
      }
    }
    return ls < rs;
  };

  double ac = 0.0, wa = accumulate(ALL(a), 0.0) + 1.0;
  while(abs(wa - ac) > 0.000001)
  {
    double wj = (ac + wa) / 2.0;
    if ( f(wj) ) ac = wj;
    else wa = wj;
  }
  printf("%.6lf\n", ac);
}

int main()
{
  fastio;
  solve();

  return 0;
}
