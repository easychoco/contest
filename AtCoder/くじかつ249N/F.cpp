#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i=a;i<(ll)n;++i)
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
  long double x, y, r;
  cin >> x >> y >> r;

  r = nextafter(r, 1LL<<60);

  ll ans = 0;
  for(int i = ceil(x - r); i <= floor(x + r); ++i)
  {
    ans += floor(y + sqrt(r*r - (x-(long double)i)*(x-(long double)i))) - ceil(y - sqrt(r*r - (x-(long double)i)*(x-(long double)i))) + 1;
  }
  show(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}