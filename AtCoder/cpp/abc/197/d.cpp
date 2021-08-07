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
  ll n, x0, y0, x2, y2;
  cin >> n;
  cin >> x0 >> y0 >> x2 >> y2;

  double mx = x0 - (x0 + x2) / 2.0;
  double my = y0 - (y0 + y2) / 2.0;
  
  double rad = 2.0 * M_PI / n;
  double cosa = cos(rad);
  double sina = sin(rad);
  double ax = mx * cosa - my * sina;
  double ay = mx * sina + my * cosa;

  printf("%.7lf %.7lf\n", ax + (x0 + x2) / 2.0, ay + (y0 + y2) / 2.0);
}

int main()
{
  fastio;
  solve();

  return 0;
}