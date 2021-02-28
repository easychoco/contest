#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i=a;i<(ll)n;++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define Show(val) cout<<(val)<<" "
#define Showln(val) cout<<(val)<<endl

using namespace std;
using ll = long long;
using P = pair<ll, ll>;
// using P = pair<int, int>;
void YN(bool a) { cout << (a ? "Yes" : "No"); }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

#define X first
#define Y second

void solve()
{
  ll n, x, y;
  cin >> n;
  vector<P> pos(n);
  rep(i, n)
  {
    cin >> x >> y;
    pos[i] = P(x, y);
  }

  sort(ALL(pos));

  bool yes = false;
  rep(i, n - 2) repi(j, i + 1, n - 1) repi(k, j + 1, n)
  {
    P p1 = pos[i], p2 = pos[j], p3 = pos[k];
    // (p2.Y - p1.Y) / (p2.X - p1.X) == (p3.Y - p1.Y) / (p3.X - p1.X);
    yes |= ((p2.Y - p1.Y) * (p3.X - p1.X) == (p2.X - p1.X) * (p3.Y - p1.Y));
  }
  YN(yes);
}

int main()
{
  fastio;
  solve();

  return 0;
}