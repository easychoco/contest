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
  ll n, q;
  cin >> n >> q;
  vector<ll> x(n), y(n);
  vector<ll> xx(n), yy(n);
  rep(i, n)
  {
    ll xi, yi;
    cin >> xi >> yi;
    xx[i] = xi - yi;
    yy[i] = xi + yi;
    x[i] = xi - yi;
    y[i] = xi + yi;
    // x[i] = make_tuple(xi - yi, i);
    // y[i] = make_tuple(xi + yi, i);
  }
  sort(ALL(x));
  sort(ALL(y));

  rep(i, q)
  {
    ll qi;
    cin >> qi;
    qi--;
    show(max(max(xx[qi] - x[0], x.back() - xx[qi]), max(yy[qi] - y[0], y.back() - yy[qi])));
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}