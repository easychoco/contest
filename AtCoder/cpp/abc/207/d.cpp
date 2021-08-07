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
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using P = pair<ll, ll>;
const ll INF = 1LL << 60;
void YN(bool a) { cout << (a ? "Yes" : "No") << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
void show(){ cout << endl; }
template <class Head, class... Tail>
void show(Head&& head, Tail&&... tail){ cout << head << " "; show(std::forward<Tail>(tail)...); }
template<class T> inline void showall(T& a) { for(auto v:a) cout<<v<<" "; cout<<endl; }


P relative(P a, P b)
{
  ll xa, ya, xb, yb;
  tie(xa, ya) = a;
  tie(xb, yb) = b;
  return make_pair(xb - xa, yb - ya);
}

void solve()
{
  ll n;
  cin >> n;
  vector<P> s(n), t(n);
  rep(i, n)
  {
    ll a, b;
    cin >> a >> b;
    s[i] = make_pair(a, b);
  }
  rep(i, n)
  {
    ll c, d;
    cin >> c >> d;
    t[i] = make_pair(c, d);
  }

  if (n == 2)
  {
    YN(abs(hypot(s[0].first - s[1].first, s[0].second - s[1].second) - hypot(t[0].first - t[1].first, t[0].second - t[1].second)) < 0.0001);
    return;
  }

  vector<P> rel(s);
  sort(ALL(rel));
  rrep(i, n - 1)
  {
    rel[i] = relative(rel[0], rel[i]);
  }

  rep(deg, 360)
  {
    double sn = sin(M_PI * deg / 180.0);
    double cs = cos(M_PI * deg / 180.0);
    vector<pair<double, double>> rotd(n);
    rep(i, n)
    {
      ll rx, ry;
      tie(rx, ry) = t[i];
      double x = (rx * cs - ry * sn);
      double y = (rx * sn + ry * cs);
      rotd[i] = make_pair(x, y);
    }

    rep(bi, n)
    {
      auto base = rotd[bi];
      rep(i, n)
      {
        double xa, ya, xb, yb;
        tie(xa, ya) = base;
        tie(xb, yb) = rotd[i];
        rotd[i] = make_pair(xb - xa, yb - ya);
      }

      vector<P> rot(n);
      rep(i, n)
      {
        double x, y;
        tie(x, y) = rotd[i];
        if (x > 0) x += 0.00001;
        else x -= 0.00001;
        if (y > 0) y += 0.00001;
        else y -= 0.00001;
        if (fmodl(x, 1.0) < 0.001 && fmodl(y, 1.0) < 0.001) rot[i] = make_pair((ll)(x), (ll)(y));
        else rot[i] = make_pair(100, -100);
      }

      sort(ALL(rot));
      if (rel == rot)
      {
        YN(true);
        return;
      }
    }
  }
  YN(false);
}

int main()
{
  fastio;
  solve();

  return 0;
}